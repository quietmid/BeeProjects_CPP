
#include <iostream>
#include <string>
#include <fstream>

#define ARGC 0
#define INP 1
#define OUTP 2

// std::string::replace is forbidden

int	errors(int msg)
{
	if (msg == ARGC)
		std::cerr << "invalid arguments count" << std::endl;
	else if (msg == INP)
		std::cerr << "invalid arguments" << std::endl;
	else if (msg == OUTP)
		std::cerr << "output error" << std::endl;
	return 1;
}

void	replaceStr(std::ofstream &fileOut, std::string s1, std::string s2, std::string buff)
{
	std::string result;
	size_t pos = 0;
	size_t start = 0;

    while ((pos = buff.find(s1, start)) != std::string::npos) // std::string::npos means that s1 was not found in buff
	{
        result.append(buff, start, pos - start);  // Append the part before s1
        result.append(s2);
        start = pos + s1.length(); // Move past the last replaced substring
    }
    result.append(buff, start, std::string::npos); // append the rest
    fileOut << result << std::endl;
}

int main (int argc, char **argv)
{
	std::ifstream file(argv[1]);
	std::ofstream fileOut;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string fileName;
	std::string fileReplace;
	std::string buff;

	if (argc != 4)
		return (errors(ARGC));
	if (!file.is_open() || s1.empty() || s2.empty())
		return (errors(INP));
	fileName = argv[1];
	fileReplace = fileName + ".replace";
	fileOut.open(fileReplace);
	if (!fileOut.is_open())
		return (errors(OUTP));
	while (getline(file, buff))
		replaceStr(fileOut, s1, s2, buff);
	file.close();
	fileOut.close();
	return 0;
}
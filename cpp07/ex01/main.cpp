#include "iter.hpp"
#include <string>

void printInt(int& i)
{
	std::cout << i + 2 << std::endl;
}

void printStrIfVowel(std::string &str)
{
	char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	for (char c : str) 
	{
		for (char v : vowels)
		{
			if (c == v)
			{
				std::cout << str << std::endl;
				return;
			}
		}
	}
	std::cout << "No vowels in: " << str << std::endl;
}

void printChar(char& c)
{
	std::cout << c << " ";
}

int main()
{
	int intArray[] = {1, 2 ,3 ,4 ,5};
	std::cout << "--- Int Array: ------" << std::endl;
	iter(intArray, 5, printInt);
	std::cout << "----- String Array: -----" << std::endl;
	std::string strArray[] = {"Hello", "World", "skzzzzz", "jObbbbb", "tyrwqq"};
	iter(strArray, 5, printStrIfVowel);
	std::cout << "---- Char Array: -----" << std::endl;
	char letters[] = {'b', 'E', 'e', ' ', 'H','i', 'V', 'e'};
	iter(letters, 8, printChar);
	std::cout << std::endl;

	return 0;
}
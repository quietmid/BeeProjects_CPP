
#include <iostream>
#include <string>
#include <fstream>
#include "Replace.hpp"

// std::string::replace is forbidden

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid arguments count" << std::endl;
		return 0;
	}
	std::ifstream file(argv[1]);
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!file.is_open() || s1.empty() || s2.empty())
	{
		std::cout << "invalid arguments" << std::endl;
		return 0;
	}
	std::string filename = argv[1];
	return 0;
}
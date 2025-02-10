#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter x;
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	x.convert(argv[1]);
	return 0;
}
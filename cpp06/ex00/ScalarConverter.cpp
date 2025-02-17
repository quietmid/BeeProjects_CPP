#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
	// std::cout << "ScalarConverter Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &str) 
{
	// std::cout << "ScalarConverter Param Constructor Called" << std::endl;
	(void)str;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	// std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
	(void)copy;
}

ScalarConverter::~ScalarConverter() 
{
	// std::cout << "ScalarConverter Destructor Called" << std::endl;
}

void ScalarConverter::convert(const std::string &str) 
{
	ScalarConverter x;
	// need to conver the string to

	// if its not displayable then display 'non displayable'
	// char: c,a,* 
	// int: 0
	x.toInt(str);
	// if (x.isInt(str))
	// {
	// 	std::cout << "int: " << str << " true " << std::endl;
	// 	x.toInt(str);
	// }
	// else 
	// {
	// 	std::cout << str << " not an int" << std::endl;
	// 	x.toInt(str);
	// }
	// float: 42.0F 
	// double: 42.0

}
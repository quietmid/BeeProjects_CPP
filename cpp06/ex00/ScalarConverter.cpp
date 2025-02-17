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

type ScalarConverter::getType(const std::string str)
{
	int i = 0;
	int dot = 0;
	int afterDot = 0;
	int hasChar = 0;
	int sign = 0;

	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return SPECIALFLOAT;
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		return SPECIALDOUBLE;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign++;
	}
	while (str[i] != '\0')
	{
		if (dot)
			afterDot++;
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] == '.')
			dot++;
		else if (str[i] == '-' || str[i] == '+')
			sign++;
		else 
			hasChar++;
		i++;
	}
	if (dot > 1 || hasChar > 1 || sign > 1)
		return INVALID;
	else if (afterDot && str.back() != 'f')
		return DOUBLE;
	else if (afterDot && str.back() == 'f')
		return FLOAT;
	else if (hasChar)
		return CHAR;
	else
		return INT;
}

void ScalarConverter::convert(const std::string &str) 
{
	// first detect the type of the input
	// then convert it to the other three types
	type t = getType(str);
	std::cout << "type: " << t << std::endl;

}
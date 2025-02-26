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

static int nonDisplayableChar(std::string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return 1;
		i++;
	}
	return 0;
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
	{
		try {
			double num = std::stod(str);
			if (num >= MIN_DOUBLE && num <= MAX_DOUBLE)
				return DOUBLE;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return INVALID;
		}
	}
	else if (afterDot && str.back() == 'f')
	{
		try {
			float num = std::stof(str);
			if (num >= MIN_FLOAT && num <= MAX_FLOAT)
				return FLOAT;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return INVALID;
		}
	}
	else if (hasChar)
		return CHAR;
	else
	{
		try {
			int num = std::stoi(str);
			if (num >= MIN_INT && num <= MAX_INT)
				return INT;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return INVALID;
		}
	}
	return INVALID;
}

void printType(type t)
{
	std::cout << "type: ";
	switch(t) 
	{
		case (CHAR):
			std::cout << "Char" << std::endl;
			break;
		case (INT):
			std::cout << "Int" << std::endl;
			break;
		case (FLOAT):
			std::cout << "Float" << std::endl;
			break;
		case (SPECIALFLOAT):
			std::cout << "Float" << std::endl;
			break;
		case (DOUBLE):
			std::cout << "Double" << std::endl;
			break;
		case (SPECIALDOUBLE):
			std::cout << "Double" << std::endl;
			break;
		case (INVALID):
			std::cout << "Invalid Input" << std::endl;
			break;
	}
}

void ScalarConverter::convert(const std::string &str) 
{
	// first detect the type of the input
	// then convert it to the other three types
	if (nonDisplayableChar(str))
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	type t = getType(str);
	printType(t);
	char _c = 0;
	int _i = 0;
	float _f = 0.0f;
	double _d = 0.0;
	bool isSpecial = false;
	switch(t)
	{
		case CHAR:
			_c = str[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;
		case INT:
			_i = std::stoi(str);
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;
		case FLOAT:
			_f = std::stof(str);
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break;
		case SPECIALFLOAT:
			isSpecial = true;
			break;
		case DOUBLE:
			_d = std::stod(str);
			_c = static_cast<char>(_d);
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
			break;
		case SPECIALDOUBLE:
			isSpecial = true;
			break;
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			return;
	}
	if (!isSpecial)
	{
		if (_c < 32 || _c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << _c << std::endl;
		std::cout << "int: " << _i << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "float: " << _f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "double: " << _d << std::endl;
	}
	else if (t == 5)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::string newFloat;
		if (str.compare("-inf") == 0)
			newFloat = "-inff";
		else if (str.compare("+inf") == 0)
			newFloat = "+inff";
		else
			newFloat = "nanf";
		std::cout << "float: " << newFloat << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else if (t == 3)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::string newDouble;
		if (str.compare("-inff") == 0)
			newDouble = "-inf";
		else if (str.compare("+inff") == 0)
			newDouble = "+inf";
		else
			newDouble = "nan";
		std::cout << "double: " << newDouble << std::endl;
	}
}
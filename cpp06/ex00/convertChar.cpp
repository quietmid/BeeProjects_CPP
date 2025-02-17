#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &str)
{
	int i = std::stoi(str);
	if (str.size() == 1 && !isdigit(str[0]))
		return true;
	else if ()
	return false;
}

void ScalarConverter::toChar(const std::string &str) 
{
	// need to conver the string to
	// char: c,a,* 
	// if its not displayable then display 'non displayable'
	char c;

	if (str.size() == 1 && !isdigit(str[0]))
		c = str[0];
	else if
	{
		c = static_cast<char>(std::stoi(str));
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
		return ;
	}
	return c;
}
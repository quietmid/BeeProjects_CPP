#include "ScalarConverter.hpp"

bool ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return false;
	size_t dotPos = str.find('.');
	size_t fPos = str.find('f');

	std::regex intPattern(R"(^[+-]?\d+$)");
	if (std::regex_match(str, intPattern))
	{
		try
		{
			long long value = std::stoll(str);
			if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
				return false;
			return true;
		}
		catch(const std::exception& e)
		{
			return false;
		}
	}
	else if (dotPos != std::string::npos)
	{
		if (dotPos + 1 >= str.size())
			return false;
		else if (fPos != std::string::npos && fPos != str.size() - 1)
			return false;
		for (size_t i = dotPos + 1; i < str.size(); i++)
		{
			if (i == fPos)
				break;
			if (str[i] != '0')
				return false;
		}
		try
		{
			long long value = std::stoll(str.substr(0, dotPos));
			if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
				return false;
			return true;
		} catch (const std::exception& e)
		{
			return false;
		}
	}
	return false;
}

void ScalarConverter::toInt(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	size_t dotPos = str.find('.');
	size_t fPos = str.find('f');
	std::string intStr;

	if (isInt(str))
	{
		if (dotPos != std::string::npos)
			intStr = str.substr(0, dotPos);
		else if (fPos != std::string::npos)
			intStr = str.substr(0, fPos);
		else
			intStr = str;
		std::cout << "int: " << intStr << std::endl;
	}
	else 
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
}
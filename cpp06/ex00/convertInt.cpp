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
		long long value = std::stoll(str);
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            return false;
		return true;
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
		long long value = std::stoll(str.substr(0, dotPos));
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			return false;
		return true;
	}
	return false;
}
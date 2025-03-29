#pragma once

#include <iostream>
#include <limits> //min max
#include <iomanip> //precision

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum type
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	SPECIALFLOAT = 3,
	DOUBLE = 4,
	SPECIALDOUBLE = 5,
	INVALID = -1
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const std::string &str);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();

		static type getType(const std::string str);
	public:
		static void convert(const std::string &str);
};
	
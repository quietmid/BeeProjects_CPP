#pragma once

#include <iostream>
#include <regex>
#include <limits>

class ScalarConverter
{
	private:
		char _c;
		int _i;
		float _f;
		double _d;

		bool isChar(const std::string &str);
		bool isInt(const std::string &str);
		bool isFloat(const std::string &str);
		bool isDouble(const std::string &str);

		void toChar(const std::string &str);
		void toInt(const std::string &str);
		void toFloat(const std::string &str);
		void toDouble(const std::string &str);

	public:
		ScalarConverter();
		ScalarConverter(const std::string &str);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();

		static void convert(const std::string &str);
};
#include <iostream>
#include "whatever.hpp"

int main() 
{
	int x = 42;
	int y = 21;
	std::cout << "Before Swap" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After Swap" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "Min = " << min(x, y) << std::endl;
	std::cout << "Max = " << max(x, y) << std::endl;
	// testing string
	std::string s1 = "Hello";
	std::string s2 = "Hellw";
	std::cout << "Before Swap" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "After Swap" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "Min = " << min(s1, s2) << std::endl;
	std::cout << "Max = " << max(s1, s2) << std::endl;

	// // testing if equals, it display the end of the string

	// int a = 42;
	// int b = 42;
	// if (&min(a, b) == &a)
	// 	std::cout << "min(a, b) is a" << std::endl;
	// else
	// 	std::cout << "min(a, b) is b" << std::endl;
	// if (&max(a, b) == &a)
	// 	std::cout << "max(a, b) is a" << std::endl;
	// else
	// 	std::cout << "max(a, b) is b" << std::endl;
	return 0;
}
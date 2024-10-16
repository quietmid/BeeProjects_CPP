
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b ( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << " is a" << std::endl;
	std::cout << b.getRawBits() << " is b" << std::endl;
	std::cout << "c is " << c.getRawBits() << std::endl;
	a.setRawBits(5);
	std::cout << a.getRawBits() << " is a" << std::endl;

};
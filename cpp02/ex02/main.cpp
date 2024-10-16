 
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "a is now: " << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a is now: " << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a is now: " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: "<<Fixed::min( a, b ) << std::endl;
    // // Test comparison operators
    // std::cout << "a > b: " << (a > b) << std::endl;
    // std::cout << "a < b: " << (a < b) << std::endl;
    // std::cout << "a >= b: " << (a >= b) << std::endl;
    // std::cout << "a <= b: " << (a <= b) << std::endl;
    // std::cout << "a == b: " << (a == b) << std::endl;
    // std::cout << "a != b: " << (a != b) << std::endl;
	// // Arithmetic operators
	// Fixed const c(10);
	// Fixed const d(20.25f);

	// std::cout << "d - c " << (d - c) << std::endl;
	// std::cout << "c + d " << (c + d) << std::endl;
	// std::cout << "c * d " << (c * d) << std::endl;
	// std::cout << "d / c " << (d / c) << std::endl;
	return 0;
};

/*
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/

/* EXTRA test */
/*
    // Test comparison operators
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
	*/
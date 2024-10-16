
#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	fixedPointValue;
		static const int frac_bits_value;
	public:
		Fixed(); // default constructor
		Fixed (const Fixed &copy); // copy constructor
		~Fixed(); // destructor
		Fixed & operator = (const Fixed &copy); // copy assignment operator
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};

#endif
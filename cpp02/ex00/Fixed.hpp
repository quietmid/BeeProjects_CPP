
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
		Fixed();
		Fixed (const Fixed &copy);
		~Fixed();
		Fixed & operator = (const Fixed &copy);
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};

#endif
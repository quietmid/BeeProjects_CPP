
#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedPointValue;
		static const int frac_bits;
	public:
	// Constructors
		Fixed();
		Fixed(const int input);
		Fixed(const double input);
		Fixed(const Fixed &copy);
	// Destructors
		~Fixed();
	// Overloaded Operators
		Fixed &operator=(const Fixed &copy);
	// Getter
		int	getRawBits(void) const;
	// Setter
		void setRawBits(int const raw);
	// member functions
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &obj, Fixed const &_fp);
#endif
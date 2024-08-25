
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
	// Comparison operators
		bool operator >(const Fixed &src) const;
		bool operator <(const Fixed &src) const;
		bool operator >=(const Fixed &src) const;
		bool operator <=(const Fixed &src) const;
		bool operator ==(const Fixed &src) const;
		bool operator !=(const Fixed &src) const;
	// Arithmetic operators
		Fixed operator +(Fixed const &src) const;
		Fixed operator -(Fixed const &src) const;
		Fixed operator *(Fixed const &src) const;
		Fixed operator /(Fixed const &src) const;
	// Incre/Decre operators
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
	// Getter
		int	getRawBits(void) const;
	// Setter
		void setRawBits(int const raw);
	// member functions
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &obj, Fixed const &_fp);

#endif
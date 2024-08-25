
#include "Fixed.hpp"

const int Fixed::frac_bits = 8;
// Constructors
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

Fixed::Fixed(const int input)
{
	std::cout << "Int Constructor called" << std::endl;
	this->fixedPointValue = input << this->frac_bits;
};

Fixed::Fixed(const double input)
{
	std::cout << "Float Constructor called" << std::endl;
	this->fixedPointValue = roundf(input * (1 << this->frac_bits));
};

// Destructors
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};
// Overloaded Operators
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedPointValue = copy.getRawBits();
	return *this;
};
// Getters and Setters
int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
 	return (this->fixedPointValue);
};

void Fixed::setRawBits( int const raw)
{
	this->fixedPointValue = raw;
};

// Member Functions

float Fixed::toFloat(void) const
{
	double result;
	result = (double)this->fixedPointValue / (double)(1 << this->frac_bits);
	return (result);
};

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->frac_bits);
};

std::ostream &operator<<(std::ostream &obj, Fixed const &_fp)
{
	obj << _fp.toFloat();
	return (obj);
};
// Comparison operators
bool Fixed::operator >(const Fixed &src) const
{
	return (this->fixedPointValue > src.fixedPointValue);
};

bool Fixed::operator <(const Fixed &src) const
{
	return (this->fixedPointValue < src.fixedPointValue);
};

bool Fixed::operator >=(const Fixed &src) const
{
	return (this->fixedPointValue >= src.fixedPointValue);
};

bool Fixed::operator <=(const Fixed &src) const
{
	return (this->fixedPointValue <= src.fixedPointValue);
};

bool Fixed::operator ==(const Fixed &src) const
{
	return (this->fixedPointValue == src.fixedPointValue);
};

bool Fixed::operator !=(const Fixed &src) const
{
	return (this->fixedPointValue != src.fixedPointValue);
};
// Arithmetic operators

Fixed Fixed::operator +(Fixed const &src) const
{
	Fixed result;

	result.setRawBits(this->fixedPointValue + src.fixedPointValue);
	return (result);
};

Fixed Fixed::operator -(Fixed const &src) const
{
	Fixed result;

	result.setRawBits(this->fixedPointValue - src.fixedPointValue);
	return (result);
};

Fixed Fixed::operator *(Fixed const &src) const
{
	Fixed result;

	result.setRawBits((this->fixedPointValue * src.fixedPointValue) >> this->frac_bits);
	return (result);
};

Fixed Fixed::operator /(Fixed const &src) const
{
	Fixed result;

	result.setRawBits((this->fixedPointValue << this->frac_bits) / src.fixedPointValue);
	return (result);
};

//Incre/Decre Operator

Fixed& Fixed::operator++() // Pre increment
{
	++fixedPointValue;
	return (*this);
};

Fixed Fixed::operator++(int) //Post increment;
{
	Fixed temp = *this;

	++fixedPointValue;
	return temp;
};

Fixed& Fixed::operator--()
{
	--fixedPointValue;
	return (*this);
};

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--fixedPointValue;
	return (temp);
};

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
};

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
};

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
};

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
};
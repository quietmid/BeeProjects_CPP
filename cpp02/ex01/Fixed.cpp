
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

/*input x 256 as frac_bit 8 = 256 in binary*/
// converts the int input into the fixedpointvalue
Fixed::Fixed(const int input)
{
	std::cout << "Int Constructor called" << std::endl;
	this->fixedPointValue = input << this->frac_bits;
};

// converts the float input into fixedpointvalue
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
	return (float)this->fixedPointValue / (1 << this->frac_bits);
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
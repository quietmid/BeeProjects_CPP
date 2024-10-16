
#include "Fixed.hpp"

const int Fixed::frac_bits_value = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedPointValue = copy.getRawBits();
	return *this;
};

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
 	return (this->fixedPointValue);
};

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits called, setting the value to " << raw << std::endl;
	this->fixedPointValue = raw;
};

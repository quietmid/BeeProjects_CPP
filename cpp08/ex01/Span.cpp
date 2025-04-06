#include "Span.hpp"

Span::Span() : _n(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Span Parametric constructor called" << std::endl;

}

Span::Span(const Span &copy)
{
	std::cout << "Span Copy constructor called" << std::endl;
	*this = copy;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(const Span& copy)
{
	std::cout << "Span = operator called" << std::endl;
	if (this != &copy)
	{
		this->_n = copy._n;
		this->_vect = copy._vect;
	}
	return (*this);
}

void Span::addNumber(int x)
{
	if (this->_vect.size() >= this->_n)
		throw std::out_of_range("Span is already at max capacity");
	this->_vect.push_back(x);
}

void Span::printVect() const
{
	if (_vect.empty())
	{
		std::cout << "the vector is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "[ ";
		for (size_t i = 0; i < _vect.size(); i++)
		{
			if (i == _vect.size() - 1)
				std::cout << _vect[i];
			else
				std::cout << _vect[i] << ", ";
		}
		std::cout << " ]" << std::endl;
	}
}
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

//member functions
void Span::addNumber(int x)
{
	if (this->_vect.size() >= this->_n)
		throw std::out_of_range("Span is already at max capacity");
	this->_vect.push_back(x);
}

int Span::shortestSpan() const
{
	if (_vect.size() == 1 || _vect.empty())
		throw std::out_of_range("There is not enough in the Span to find the shortest span");
	std::vector<int> temp = _vect;
	int diff = MAX_INT;
	std::sort(temp.begin(), temp.end());
	// std::cout << "Printing temp: ";
	// for (size_t i = 0; i < temp.size(); i++)
	// {
	// 	std::cout << temp[i];
	// 	if (i != temp.size() - 1)
	// 		std::cout << ", ";
	// }
	// std::cout << std::endl;
	for (size_t i = temp.size() - 1; i > 0; i--)
	{
		if (diff > temp[i] - temp[i - 1])
			diff = temp[i] - temp[i - 1];
	}
	return diff;
}

int Span::longestSpan() const
{
	if (_vect.size() == 1 || _vect.empty())
		throw std::out_of_range("There is not enough in the Span to find the longest span");
	int minVal = *std::min_element(_vect.begin(), _vect.end());
	int maxVal = *std::max_element(_vect.begin(), _vect.end());

	return maxVal - minVal;
}

// template<typename InputIterator>
// void Span::addMultiNumbers(InputIterator begin, InputIterator end)
// {
//     size_t distance = std::distance(begin, end);
//     if (_vect.size() + distance > _n)
//         throw std::out_of_range("Can't add these many numbers");
//     _vect.insert(_vect.end(), begin, end);
// 	//insert is more efficent, cleaner.
// }

//extra
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
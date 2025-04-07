#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647

class Span 
{
	private:
		std::vector<int> _vect;
		unsigned int _n;

		Span();
	public:
		Span(unsigned int n);
		Span(const Span& copy);
		~Span();

		Span &operator=(const Span& copy);
		void addNumber(int x);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename InputIterator>
		void addMultiNumbers(InputIterator begin, InputIterator end);

		void printVect() const;
};
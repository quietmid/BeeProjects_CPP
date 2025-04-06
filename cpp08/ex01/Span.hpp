#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

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

		void addMultiNumber();

		void printVect() const;
};
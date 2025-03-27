#pragma once

template <typename T> class Array {
	private:
		T* _array;
		unsigned int _size;
	public:
	// Constructors
		Array(): _size(0)
		{
			std::cout << "Default constructor called" << std::endl;
			_array = new T[_size];
		};
		Array(unsigned int n) : _size(n) {
			if (n == 0)
				_array = nullptr;
			else
				_array = new T[n];
		};
		Array(Array const &copy): _size(copy.size())
		{
			std::cout << "Copy constructor called" << std::endl;
			_array = NULL;
			*this = copy;
		}
	// Destructor
	~Array()
	{
		std::cout << "Destructor called" << std::endl;
		if (_array)
			delete[] _array;
	}
	//Operator
};

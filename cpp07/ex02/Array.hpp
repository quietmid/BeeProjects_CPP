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
			_array = new T[_size];
			for (int i = 0; i < _size; i++)
			{
				_array[i] = copy[i];
			}
		}
	// Destructor
	~Array()
	{
		std::cout << "Destructor called" << std::endl;
		if (_array)
			delete[] _array;
	}
	//Operator
	Array &operator=(const Array &copy)
	{
		if (_array != NULL)
			delete [] _array;
		if (copy.size() != 0)
		{
			_size = copy.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = copy._array[i];
			}
		}
		else
			_array = nullptr;
		return (*this);
	}
};

#pragma once
#include <exception>

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
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = copy._array[i];
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
		if (this == &copy)
			return *this;

		delete [] _array;

		_size = copy.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = copy._array[i];
		}
		return (*this);
	}
	
	// still need subscript operator []
	T &operator[](unsigned int idx) 
	{
		if (idx >= _size)
			throw std::out_of_range("Index out of ranges");
		return _array[idx];
	}
	//member function that returns the number of elements in the array
	unsigned int size() const {
		return _size;
	}
};

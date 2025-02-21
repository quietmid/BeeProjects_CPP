#include "Serializer.hpp"


// these printouts should never appear because they can't be initialied in any way
Serializer::Serializer()
{
	std::cout << "Serializer constructor appeared" << std::endl;
}
Serializer::Serializer(const Serializer& other)
{
	std::cout << "Serializer copy constructor appeared" << std::endl;
	*this = other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
	std::cout << "Serializer assignation operator appeared" << std::endl;
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor appeared" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
#include "Serializer.hpp"

int main()
{
	Data* data = new Data;
	data->str = "Hello";
	data->n = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data* data2 = Serializer::deserialize(raw);

	std::cout << "Original Data" << std::endl;
	std::cout << "str: " << data->str << std::endl;
	std::cout << "n: " << data->n << std::endl;
	
	std::cout << std::endl;

	std::cout << "Data after serialization:" << std::endl;
	std::cout << "unique_uint_ptr: " << raw << std::endl;
	
	std::cout << std::endl;

	std::cout << "Data after derialization:" << std::endl;
	std::cout << "str: " << data2->str << std::endl;
	std::cout << "n: " << data2->n << std::endl;

	delete data;
	return 0;
}
#include "Span.hpp"

int main()
{
	Span test(5);
	try {
		test.addNumber(1);
		test.addNumber(2);
		test.addNumber(3);
		// test.addNumber(4);
		// test.addNumber(5);
		// test.addNumber(6);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	test.printVect();

	return 0;
}
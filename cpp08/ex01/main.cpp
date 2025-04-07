#include "Span.hpp"

int main()
{
	Span test(5);
	try {
		test.addNumber(10);
		test.addNumber(2);
		test.addNumber(8);
		// test.addNumber(4);
		// test.addNumber(5);
		// test.addNumber(6);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	test.printVect();
	std::cout << "Shortest span is " << test.shortestSpan() << std::endl;
	std::cout << "Longest span is " << test.longestSpan() << std::endl;

	return 0;
}
#include "Span.hpp"
#include <list>
// #include <iterator>
#include <numeric>

//from subject
// int main()
// {
// 	try {
// 		Span sp = Span(5);
// 		sp.addNumber(6);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);
// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return 0;
// }
////my own
int main()
{
	std::cout << "---- Testing 1 ----" << std::endl;
	Span test(5);
	try {
		test.addNumber(10);
		test.addNumber(2);
		test.addNumber(8);
		test.addNumber(4);
		// test.addNumber(5);
		// test.addNumber(6);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	test.printVect();
	std::cout << "Shortest span is " << test.shortestSpan() << std::endl;
	std::cout << "Longest span is " << test.longestSpan() << std::endl;
	Span testA(3);
	try {
		testA.addNumber(1);
		testA.addNumber(3);
		testA.addNumber(5);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	testA.printVect();
	testA = test;
	testA.printVect();
	std::cout << "---- Testing 2 ----" << std::endl;
	Span test2(20000);
	std::list<int> myList1 = {10, 34, 56 , 78, 10000};
	try {
		test2.addNumber(1);
		test2.addNumber(55);
		test2.addNumber(77);
		test2.addMultiNumbers(myList1.begin(), myList1.end());
		test2.printVect();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---- Testing 3 ----" << std::endl;
	Span test3(15000);
	std::vector<int> myVector(200000);
	//iota used to fill a range with sequentially increasing values (begin,end = iterators defining the range to fill, value = the starting value to assign)
	// myVector.begin() + 14000
	std::iota(myVector.begin(), myVector.end(), 0);
	try 
	{
		test3.addMultiNumbers(myVector.begin(), myVector.end());
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---- Testing 4 ----" << std::endl;
	Span test4(25000);
	std::vector<int> myVector2(15000);
	// std::list<int> myList2(20000);
 	std::iota(myVector2.begin(), myVector2.begin() + 100, 0);
 	// std::iota(myList2.begin(), myList2.end(), 0);
	try 
	{
		test4.addMultiNumbers(myVector2.begin(), myVector2.end());
		// test4.addMultiNumbers(myList2.begin(), myList2.end());
		// test4.printVect();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "shortest span is: " << test4.shortestSpan() << std::endl;
	std::cout << "longest span is: " << test4.longestSpan() << std::endl;
	std::cout << "---- Testing 5 ----" << std::endl;
	Span edgeCase(3);
	try {
		edgeCase.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		edgeCase.addNumber(42);
		edgeCase.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---- Testing 6 ----" << std::endl;
	Span edgeCase2(0);
	try {
		edgeCase2.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		edgeCase2.addNumber(42);
		edgeCase2.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
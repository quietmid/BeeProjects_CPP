#include <iostream>
#include <vector>
#include "whatever.hpp"

template<typename T>
void printVector(const std::vector<T>& vec) {
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";
	}
	std::cout << "]";
}

int main() 
{
	int x = 42;
	int y = 21;
	std::cout << "Before Swap" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After Swap" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "Min = " << min(x, y) << std::endl;
	std::cout << "Max = " << max(x, y) << std::endl;
	// testing string
	std::string s1 = "Hello";
	std::string s2 = "Hellw";
	std::cout << "Before Swap" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "After Swap" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "Min = " << min(s1, s2) << std::endl;
	std::cout << "Max = " << max(s1, s2) << std::endl;
	//testing float
	float num1 = 2.5f;
	float num2 = 65.4f;
	std::cout << "Before Swap" << std::endl;
	std::cout << "float 1 = " << num1 << ", float 2 = " << num2 << std::endl;
	std::cout << "Min = " << min(num1, num2) << std::endl;
	std::cout << "Max = " << max(num1, num2) << std::endl;
	swap(num1, num2);
	std::cout << "After Swap" << std::endl;
	std::cout << "float 1 = " << num1 << ", float 2 = " << num2 << std::endl;
	std::cout << "Min = " << min(num1, num2) << std::endl;
	std::cout << "Max = " << max(num1, num2) << std::endl;
	//testing vector
	std::vector<int> v1 = {1, 3, 5};
	std::vector<int> v2 = {2, 4, 6};
	std::cout << "Before Swap" << std::endl;
	std::cout << "Vector 1 = ";
	printVector(v1);
	std::cout << ", Vector 2 = ";
	printVector(v2);
	std::cout << std::endl;
	std::cout << "Min = "; 
	printVector(min(v1, v2));
	std::cout << std::endl;
	std::cout << "Max = "; 
	printVector(max(v1, v2));
	std::cout << std::endl;
	swap(v1, v2);
	std::cout << "Vector 1 = ";
	printVector(v1);
	std::cout << ", Vector 2 = ";
	printVector(v2);

	// // testing if equals, it display the end of the string
	// int a = 42;
	// int b = 42;
	// if (&min(a, b) == &a)
	// 	std::cout << "min(a, b) is a" << std::endl;
	// else
	// 	std::cout << "min(a, b) is b" << std::endl;
	// if (&max(a, b) == &a)
	// 	std::cout << "max(a, b) is a" << std::endl;
	// else
	// 	std::cout << "max(a, b) is b" << std::endl;
	return 0;
}
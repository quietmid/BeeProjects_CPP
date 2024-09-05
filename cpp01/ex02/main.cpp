
#include <string>
#include <iostream>

/*
Usually memory addresses are represented in hexadecimal. 
In c++ you can get the memory address of a variable by using the & operator, 
like:
cout << &i << endl;
*/

int main (void)
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString; //stores the memory address
    std::string &stringREF = myString; // an alias to an existing variable 

    std::cout << "Memory address of the following:" << std::endl;
    std::cout << "Memory address of " << myString << " is " << &myString << std::endl;
    std::cout << "Memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF is " << &stringREF << std::endl;
    std::cout << "--------- I am a dividing line-----------------" << std::endl;
    std::cout << "Value of the following:" << std::endl;
    std::cout << "The value of myString is " << myString << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl;
    std::cout << "The value of myString is " << stringREF << std::endl;

   return 0;
}
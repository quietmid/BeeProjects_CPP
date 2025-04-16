#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
        std::cout << "Error: not enough arg counts" << std::endl;
    PmergeMe sorting;

    if (sorting.checkInput(argv))
    {
        std::cout << "Before: ";
        sorting.printVect();
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}
#include "PmergeMe.hpp"

//./PmergeMe $(jot -r 3000 1 100000)
//./PmergeMe $(shuf -i 1-100000 -n 3000)

int main(int argc, char** argv)
{
    if (argc < 2)
        std::cout << "Error: not enough arg counts" << std::endl;
    PmergeMe sorting;

    if (sorting.checkInput(argv))
    {
        std::cout << "Before: ";
        sorting.printVect();
        sorting.sortVector();
        sorting.sortDeque();
        std::cout << "After: ";
        sorting.printVect();
        // sorting.printDeque();
        sorting.printTime();
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}
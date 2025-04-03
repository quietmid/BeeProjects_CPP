#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
    }
    //testing copy
    Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != numbers[i])
        {
            std::cerr << "didn't have the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "----changing a copied array----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        test[i] = value;
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != test[i])
        {
            std::cerr << "didn't have the same value!!" << std::endl;
            break;
            // return 1;
        }
    }

    std::cout << "-----Testing copied with the original----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != test[i])
        {
            std::cerr << "didn't have the same value!!" << std::endl;
            break;
            // return 1;
        }
    }
    //catching out of ranges
    std::cout << "----out of ranges test----" << std::endl;
    try
    {
        std::cout << "   testign numbers[-2]   " << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "   testign numbers[MAX VALUE]   " << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
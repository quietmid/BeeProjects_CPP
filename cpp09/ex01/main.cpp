#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: invalid number of arg count" << std::endl;
        std::cout << "Example: ./RPN '3 4 + 5 *' " << std::endl;
        return 1;
    }
    rpn calculator;
    try {
        int answer = calculator.revPolishNotation(argv[1]);
        std::cout << answer << std::endl;
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
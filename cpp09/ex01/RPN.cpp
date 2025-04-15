#include "RPN.hpp"

rpn::rpn()
{
    // std::cout << "RPN constructor called" << std::endl;
}

rpn::rpn(const rpn &copy)
{
    // std::cout << "RPN copy constructor called" << std::endl;
    *this = copy;
}

rpn::~rpn()
{
    // std::cout << "RPN destructor called" << std::endl;
}

rpn& rpn::operator=(const rpn& copy)
{
    // std::cout << "RPN = operator called" << std::endl;
    if (this != &copy)
    {
        this->_numbers = copy._numbers;
        this->_operators = copy._operators;
    }
    return (*this);
}

int rpn::revPolishNotation(const std::string &input)
{
    std::istringstream iss(input); // Token-based parsing
    std::string token;
    int operandCount = 0;

    while (iss >> token)
    {
        // Check if token is a number
        if (std::all_of(token.begin(), token.end(), ::isdigit))
        {
            int number = std::stoi(token);
            if (number >= 10) // Catch numbers >= 10
                throw valueTooHigh();

            _numbers.push(number);
            operandCount++;
        }
        // Check if token is a valid operator
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (operandCount < 2)
                throw invalidRpnInput();

            int b = _numbers.top(); _numbers.pop();
            int a = _numbers.top(); _numbers.pop();

            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("division by zero");
                result = a / b;
            }

            _numbers.push(result);
            operandCount--;
        }
        else
        {
            throw invalidOperators(); // Invalid token (e.g., letters, symbols)
        }
    }

    if (operandCount != 1)
        throw invalidRpnInput();

    return _numbers.top();
}


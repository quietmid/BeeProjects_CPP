#include "RPN.hpp"

rpn::rpn()
{
    std::cout << "RPN constructor called" << std::endl;
}

rpn::rpn(const rpn &copy)
{
    std::cout << "RPN copy constructor called" << std::endl;
    *this = copy;
}

rpn::~rpn()
{
    std::cout << "RPN destructor called" << std::endl;
}

rpn& rpn::operator=(const rpn& copy)
{
    std::cout << "RPN = operator called" << std::endl;
    if (this != &copy)
    {
        this->_numbers = copy._numbers;
        this->_operators = copy._operators;
    }
    return (*this);
}


// void rpn::checkInput(const std::string &input)
// {
//     int operandCount = 0;
//     for (size_t i = 0; i < input.size(); i++) 
//     {
//         char ch = input[i];

//         if (std::isspace(ch))
//             continue;
//                     // Check if the character is a digit
//         if (std::isdigit(ch)) 
//         {
//             int number = ch - '0'; // Convert char to int
//             if (number > 10) {
//                 throw valueTooHigh();
//             }
//             addNumber(number);
//             operandCount++;
//         }
//         // Check if the character is a valid operator
//         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
//         {
//             if (operandCount < 2)
//                 throw invalidRpnInput();
//             addOperator(ch);
//             operandCount--;
//         }
//         // If the character is invalid, throw an exception
//         else {
//             throw invalidOperators();
//         }
//     }
//     if (operandCount != 1)
//         throw invalidRpnInput();
// }

// void rpn::addNumber(int x)
// {
//     _numbers.push(x);
// }

// void rpn::addOperator(char y)
// {
//     _operators.push(y);
// }

int rpn::revPolishNotation(const std::string &input)
{
    int operandCount = 0;
    for (size_t i = 0; i < input.size(); i++) 
    {
        char ch = input[i];

        if (std::isspace(ch))
            continue;
                    // Check if the character is a digit
        if (std::isdigit(ch)) 
        {
            int number = ch - '0'; // Convert char to int
            if (number > 10) {
                throw valueTooHigh();
            }
            _numbers.push(number);
            operandCount++;
        }
        // Check if the character is a valid operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
            if (operandCount < 2)
                throw invalidRpnInput();
            int b = _numbers.top();
            _numbers.pop();
            int a = _numbers.top();
            _numbers.pop();

            int result;
            switch(ch)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("division by zero");
                    result = a / b;
                    break;
                default:
                    throw invalidOperators();
            }
            _numbers.push(result);
            operandCount--;
        }
        // If the character is invalid, throw an exception
        else {
            throw invalidOperators();
        }
    }
    if (operandCount != 1)
        throw invalidRpnInput();
    return _numbers.top();
}


void rpn::printNums()
{
    std::stack<int> temp = _numbers;
    std::cout << "[";
    while(!temp.empty())
    {
        std::cout << temp.top();
        temp.pop();
        if (!temp.empty())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void rpn::printOps()
{
    std::stack<char> temp = _operators;
    std::stack<char> reversed;

    // Transfer elements from the original stack to the reversed stack
    while (!temp.empty()) {
        reversed.push(temp.top());
        temp.pop();
    }

    std::cout << "[";
    while(!reversed.empty())
    {
        std::cout << reversed.top();
        reversed.pop();
        if (!reversed.empty())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
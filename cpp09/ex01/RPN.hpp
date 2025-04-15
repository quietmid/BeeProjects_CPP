#pragma once

// #include <iostream>
#include <stack>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <exception>
#include <cctype>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648

class valueTooHigh : public std::exception
{
    public:
        virtual const char* what() const noexcept override {
            return "Value has to be less than 10.";
        }
};

class invalidOperators : public std::exception
{
    public:
        virtual const char* what() const noexcept override {
            return "Invalid Operators.";
        }
};

class invalidRpnInput : public std::exception
{
    public:
        virtual const char* what() const noexcept override {
            return "This is an invalid input of Reversed Polish Notation";
        }
};

class rpn 
{
    private:
        std::stack<int> _numbers;
        std::stack<char> _operators;
    public:
        rpn();
        rpn(const rpn& copy);
        ~rpn();

        rpn &operator=(const rpn& copy);
        int revPolishNotation(const std::string &input);
};


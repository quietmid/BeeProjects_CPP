#pragma once

#include <iostream> // need to check if i need this
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>
#include <cstdlib>

class PmergeMe
{
    private:
        int _numOfEle;
        std::vector<int> _elements;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe& copy);
        bool checkInput(char **input);

        //setter
        void setNum(int x);
        void printVect() const;
};
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
        std::deque<int> _values;

        void vectMergeInsertSort(std::vector<int>& arr);
        void vectBinaryInsert(std::vector<int>& sorted, int value);
        std::vector<int> vectGenJacobsthalInd(int n);
        
        void dequMergeInsertSort(std::deque<int>& arr);
        void dequBinaryInsert(std::deque<int>& sorted, int value);
        std::deque<int> dequGenJacobsthalInd(int n);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe& copy);
        bool checkInput(char **input);
        void sortVector();
        void sortDeque();
  
        void printVect() const;
};
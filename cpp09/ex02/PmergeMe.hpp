#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <chrono> // for time

class PmergeMe
{
    private:
        int _numOfEle;
        std::vector<int> _elements;
        std::deque<int> _values;

        bool _vectSorted;
        bool _dequeSorted;

        double _durationVect;
        double _durationDeque;

        void vectMergeInsertSort(std::vector<int>& arr);
        void vectBinaryInsert(std::vector<int>& sorted, int value);
        std::vector<int> vectGenJacobsthalInd(int n);
        
        void dequMergeInsertSort(std::deque<int>& arr);
        void dequBinaryInsert(std::deque<int>& sorted, int value);
        std::deque<int> dequGenJacobsthalInd(int n);

        bool checkResult();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe& copy);
        bool checkInput(char **input);
        void sortVector();
        void sortDeque();
  
        void printVect() const;
        void printDeque() const;
        void printTime();
};
#include "PmergeMe.hpp"

// first pair up the int in the list
// by grouping them into adjacent pairs
// compare each pair and put the smaller number into the winner list and the bigger number into the loser list 
// if the number is odd, the leftout number goes into the winner list 
// we sort the winner list from small to large, using any sorting method(?) or maybe I have to use the recursive Ford-Johnson method
// keep ford-johnson sorting until vector.size() == 2 then we sort
// then we insert the number from the loser list one by one by searching where it belongs
//using the binary insertion

static bool isValidPositiveInt(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    try {
        long long val = std::stoll(str);
        if (val >= 0 && val <= INT_MAX)
            return (true);
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return (false);
}

PmergeMe::PmergeMe() : _numOfEle(0), _vectSorted(0), _dequeSorted(0)
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    *this = copy;
}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
    if (this != &copy)
    {
        this->_numOfEle = copy._numOfEle;
    }
    return (*this);
}

bool PmergeMe::checkInput(char** input)
{
    std::vector<int> elements;
    std::deque<int> values;

    for (int i = 1; input[i] != NULL; i++)
    {
        std::stringstream ss(input[i]);
        std::string token;

        while (ss >> token)
        {
            if (!isValidPositiveInt(token))
            {
                std::cerr << "Invalid input: " << token << std::endl;
                return false;
            }

            int number = std::stoi(token);
            elements.push_back(number);
            values.push_back(number);
        }
    }
    _numOfEle = elements.size();
    _elements = elements;
    _values = values;
    return true;
}

//Deque 
void PmergeMe::sortDeque()
{
    auto start = std::chrono::high_resolution_clock::now();
    if (_values.size() <= 1)
        return;
    dequMergeInsertSort(_values);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    _durationDeque = duration.count() * 1e6;
}

void PmergeMe::dequMergeInsertSort(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::deque<int> A; // large elements
    std::deque<int> B; // small elements

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second) {
            A.push_back(first);
            B.push_back(second);
        } else {
            A.push_back(second);
            B.push_back(first);
        }
    }
    if (arr.size() % 2 != 0)
        B.push_back(arr.back());
    dequMergeInsertSort(A);
    std::deque<int> jacobOrder = dequGenJacobsthalInd(B.size());
    for (int idx : jacobOrder)
    {
        if (idx >= (int)B.size()) continue;
        dequBinaryInsert(A, B[idx]);
    }
    arr = A;
}

std::deque<int> PmergeMe::dequGenJacobsthalInd(int n)
{
    std::deque<int> indices;
    std::deque<int> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < n) {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    std::deque<bool> used(n, false);
    for (int j : jacob) {
        if (j - 1 < n && !used[j - 1]) {
            indices.push_back(j - 1);
            used[j - 1] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            indices.push_back(i);
    }
    return indices;
}

void PmergeMe::dequBinaryInsert(std::deque<int>& sorted, int value)
{
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

//Vector
void PmergeMe::sortVector()
{
    auto start = std::chrono::high_resolution_clock::now();
    if (_elements.size() <= 1)
        return;
    vectMergeInsertSort(_elements);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    // Convert to microseconds (µs)
    _durationVect = duration.count() * 1e6;
}

void PmergeMe::vectMergeInsertSort(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    std::vector<int> A; //large element
    std::vector<int> B; //small element

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second) {
            A.push_back(first);
            B.push_back(second);
        } else {
            A.push_back(second);
            B.push_back(first);
        }
        // push the number to its respective stack
    }
    // the leftover element  (if odd number)
    if (arr.size() % 2 != 0)
        B.push_back(arr.back());
    // recursively sort the larger stack
    vectMergeInsertSort(A);
    //insert the smaller value in Jacobsthal order.
    //eg. [0, 2, 4, 1, 3]
    std::vector<int> jacobOrder = vectGenJacobsthalInd(B.size());
    for (int idx : jacobOrder) {
        
        if (idx >= (int)B.size()) //safety check incase when the numbers is over the size
            continue;
        vectBinaryInsert(A, B[idx]);
    }
    // Replace arr with sorted result
    arr = A;
}
// this is the Jacobsthal sequnce
//J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2 * J(n-2) 
// J(2) = 3
// J(3) = 5 J(4) = 11 J(5) = 21

std::vector<int> PmergeMe::vectGenJacobsthalInd(int n)
{
    std::vector<int> indices;
    std::vector<int> jacob;

    // Build Jacobsthal sequence up to n
    jacob.push_back(1); // 1-based indexing
    jacob.push_back(3);
    while (jacob.back() < n) {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }

    // Build insertion order
    // pushes t/f based on the jacob seq [t,f,t,f,t]
    std::vector<bool> used(n, false);
    for (int j : jacob) {
        if (j - 1 < n && !used[j - 1]) {
            indices.push_back(j - 1);
            used[j - 1] = true;
        }
    }

    // Fill remaining indices in order
    // pushes the order that's false in at the end, so that would be 1 and 3
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            indices.push_back(i);
    }
    // if n = 6 the indices would be this [0, 2, 4, 1, 3, 5]
    return indices;
}

void PmergeMe::vectBinaryInsert(std::vector<int>& sorted, int value)
{
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

//extra
bool PmergeMe::checkResult()
{
    if (!_vectSorted)
    {
        for (size_t i = 0; i < _elements.size() - 1; i++)
        {
            if (_elements[i] > _elements[i + 1])
            {
                std::cout << "vector failed" << std::endl;
                return false;
            }
        }
        _vectSorted = true;
    }
    if (!_dequeSorted)
    {
        for (size_t i = 0; i < _values.size() - 1; i++)
        {
            if (_values[i] > _values[i + 1])
            {
                std::cout << "deque failed" << std::endl;
                return false;
            }
        }
        _dequeSorted = true;
    }
    return true;
}

void PmergeMe::printTime()
{
    bool result = checkResult();

    if (result)
    {
        std::cout << "Time to process a range of " << _numOfEle << " elements with std::vector: " << _durationVect << " us" << std::endl;
        std::cout << "Time to process a range of " << _numOfEle << " elements with std::deque: " << _durationDeque << " us" << std::endl;
    }

}
void PmergeMe::printVect() const
{
	if (_elements.empty())
	{
		std::cout << "the vector is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "[ ";
		for (size_t i = 0; i < _elements.size(); i++)
		{
			if (i == _elements.size() - 1)
				std::cout << _elements[i];
			else
				std::cout << _elements[i] << ", ";
		}
		std::cout << " ]" << std::endl;
	}
}

void PmergeMe::printDeque() const
{
	if (_values.empty())
	{
		std::cout << "the vector is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "[ ";
		for (size_t i = 0; i < _values.size(); i++)
		{
			if (i == _values.size() - 1)
				std::cout << _values[i];
			else
				std::cout << _values[i] << ", ";
		}
		std::cout << " ]" << std::endl;
	}
}

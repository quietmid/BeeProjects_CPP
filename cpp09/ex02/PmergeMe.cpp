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

PmergeMe::PmergeMe() : _numOfEle(0)
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

void PmergeMe::setNum(int x)
{
    this->_numOfEle = x;
}

bool PmergeMe::checkInput(char** input)
{
    std::vector<int> elements;

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
        }
    }

    _numOfEle = elements.size();
    _elements = elements;
    return true;
}

//extra
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

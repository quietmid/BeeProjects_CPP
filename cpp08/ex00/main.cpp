#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

#define MAX_VAL 10
int main()
{
    std::cout << "---- Testing Vector-----" << std::endl;
    std::vector<int> numbers = {2, 55, 67, 900, 1, 4};
    try 
    {
        std::cout << "Found value: " << *easyfind(numbers, 900) << std::endl;
        std::cout << "Found value: " << *easyfind(numbers, 3) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---- Testing list-----" << std::endl;
    std::list<int> lists = {3, 4, 66, 23, 45};
    try
    {
        std::cout << "Found value: " << *easyfind(lists, 3) << std::endl;
        std::cout << "Found value: " << *easyfind(lists, 101) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---- Testing Deque-----" << std::endl;
    std::deque<int> deque = {0, -45, 155566666, 555, 7654, 345};
    try
    {
        std::cout << "Found value: " << *easyfind(deque, -45) << std::endl;
        std::cout << "Found value: " << *easyfind(deque, 101) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
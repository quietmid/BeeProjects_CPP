#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "MutantStack testing" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top of the stack is: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size of the stack is: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "Beginning to end: " << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "List testing" << std::endl;
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << "Top of stack is: " << list.back() << std::endl;
        list.pop_back();
        std::cout << "Size of stack is: " << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);

        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        std::cout << "Beginning to end: " << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        // std::list<int>::reverse_iterator rev_it = list.rbegin();
        // std::list<int>::reverse_iterator rev_ite = list.rend();
        // ++rev_it;
        // --rev_it;
        // std::cout << "End to beginning: " << std::endl;
        // while (rev_it != rev_ite)
        // {
        //     std::cout << *rev_it << std::endl;
        //     ++rev_it;
        // }
    }
    return 0;
}
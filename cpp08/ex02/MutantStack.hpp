#pragma once

#include <stack>
#include <deque>
#include <iostream>


template <typename T, typename D = std::deque<T>>
class MutantStack : public std::stack<T, D>
{
    public:
        using container_type = typename std::stack<T, D>::container_type;
        using iterator = typename container_type::iterator;
        using const_iterator = typename container_type::const_iterator;
        using reverse_iterator = typename container_type::reverse_iterator;
        using const_reverse_iterator = typename container_type::const_reverse_iterator;

        MutantStack();
        MutantStack(const MutantStack<T, D>& cpy);
        MutantStack& operator=(const MutantStack<T, D>& copy);
        ~MutantStack();
    

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"
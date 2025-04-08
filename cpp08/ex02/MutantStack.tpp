#include "MutantStack.hpp"

template <typename T, typename D>
MutantStack<T, D>::MutantStack() {}

template <typename T, typename D>
MutantStack<T, D>::MutantStack(const MutantStack<T, D>& copy) : std::stack<T, D>(copy) {}

template <typename T, typename D>
MutantStack<T, D>::~MutantStack() {}


//calls the assignment operator of the base class which copies to the underlying container c
template <typename T, typename D>
MutantStack<T, D>& MutantStack<T, D>::operator=(const MutantStack<T,D>& copy)
{
    if (this != &copy)
    {
        std::stack<T, D>::operator=(copy);
    }
    return *this;
}

template <typename T, typename D>
typename MutantStack<T, D>::iterator MutantStack<T, D>::begin()
{
    return this->c.begin();
}

template <typename T, typename D>
typename MutantStack<T, D>::iterator MutantStack<T, D>::end()
{
    return this->c.end();
}

template <typename T, typename D>
typename MutantStack<T, D>::const_iterator  MutantStack<T, D>::begin() const
{
    return this->c.begin();
}

template <typename T, typename D>
typename MutantStack<T, D>::const_iterator MutantStack<T, D>::end() const
{
    return this->c.end();
}

template <typename T, typename D>
typename MutantStack<T, D>::reverse_iterator MutantStack<T, D>::rbegin()
{
    return this->c.rbegin();
}

template <typename T, typename D>
typename MutantStack<T, D>::reverse_iterator MutantStack<T, D>::rend()
{
    return this->c.rend();
}
template <typename T, typename D>
typename MutantStack<T, D>::const_reverse_iterator MutantStack<T, D>::rbegin() const
{
    return this->c.rbegin();
}

template <typename T, typename D>
typename MutantStack<T, D>::const_reverse_iterator MutantStack<T, D>::rend() const
{
    return this->c.rend();
}
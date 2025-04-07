#pragma once
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>


class valueNotFound : public std::exception 
{
    public:
        virtual const char* what() const noexcept override {
            return "Value not found here.";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) 
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return it;
    } else {
        throw valueNotFound();
    }
}
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "The WrongCat constructor called" << std::endl;
};

WrongCat::WrongCat(std::string &type)
{
	this->type = type;
	std::cout << "The WrongCat parametric constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;
	std::cout << "The WrongCat COPY constructor called" << std::endl;
};

WrongCat::~WrongCat()
{
	std::cout << "The WrongCat destructor is called" << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy) {
        this->type = copy.getType();
        std::cout << "WrongCat copy assignment operator called" << std::endl;
    }
    return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "what you looking at?" << std::endl;
}
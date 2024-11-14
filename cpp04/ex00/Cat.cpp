#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "The Cat default constructor called" << std::endl;
};

Cat::Cat(std::string &type)
{
	this->type = type;
	std::cout << "The Cat parametric constructor called" << std::endl;
};

Cat::Cat(Cat const &copy) : Animal(copy)
{
	*this = copy;
	std::cout << "The cat COPY constructor called" << std::endl;
};

Cat::~Cat()
{
	std::cout << "8/9 cat's lives left" << std::endl;
};
//assignment operator
Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy) {
		this->type = copy.getType();
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
;}

//member func
void Cat::makeSound() const
{
	std::cout << "Meow what you looking at Meow" << std::endl;
};
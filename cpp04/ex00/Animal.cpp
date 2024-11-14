#include "Animal.hpp"

//Animal
Animal::Animal()
{
	this->type = "Manse";
	std::cout << "The Animal default constructor is called" << std::endl;
};

Animal::Animal(std::string &type)
{
	this->type = type;
	std::cout << "The Animal parametric constructor is called" << std::endl;
};

Animal::Animal(Animal const &type)
{
	*this = type;
	std::cout << "The Animal COPY constructor is called" << std::endl;
};

Animal::~Animal()
{
	std::cout << "The Animal destructor is called" << std::endl;
};

Animal& Animal::operator=(const Animal &copy)
{
	if (this != &copy) {
		this->type = copy.getType();
		std::cout << "Animal copy assignment operator called" << std::endl;
	}
	return (*this);
};

void Animal::makeSound() const
{
	std::cout << "mitä mitä?" << std::endl;
};

std::string const &Animal::getType() const
{
	return (this->type);
};

void Animal::setType(std::string &type)
{
	this->type = type;
};

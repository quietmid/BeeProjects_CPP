#include "animals.hpp"

//Animal
Animal::Animal()
{
	std::cout << "The Animal default constructor is called" << std::endl;
};

Animal::~Animal()
{
	std::cout << "The Animal destructor is called" << std::endl;
};

Animal const &Animal::operator=(Animal const &copy)
{
	std::cout << "Operator = called" << std::endl;
	this->type = copy.getType();
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

// Dog
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "The dog constructor called" << std::endl;
};

Dog::Dog(std::string &type)
{
	this->type = type;
	std::cout << "The dog para constructor called" << std::endl;
};

Dog::~Dog()
{
	std::cout << "what a productive day of sleeping, barking, pooping and eating" << std::endl;
};

void Dog::setType(std::string &type)
{
	this->type = type;
};

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
};

// Cat
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat has 9 lives" << std::endl;
};

Cat::~Cat()
{
	std::cout << "8/9 cat's lives left" << std::endl;
};

void Cat::setType(std::string &type)
{
	this->type = type;
};

void Cat::makeSound() const
{
	std::cout << "Meow what you looking at Meow" << std::endl;
};
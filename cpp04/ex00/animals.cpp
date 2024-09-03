#include "animals.hpp"

//Animal
Animal::Animal()
{
	this->type = "Manse";
	std::cout << "The Animal default constructor is called" << std::endl;
};

Animal::Animal(std::string &type)
{
	this->type = type;
	std::cout << "The Animal PARA constructor is called" << std::endl;
};

Animal::Animal(Animal const &type)
{
	this->type = type.getType();
	std::cout << "The Animal COPY constructor is called" << std::endl;
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
	std::cout << "The dog PARA constructor called" << std::endl;
};

Dog::Dog(Dog const &copy)
{
	this->type = copy.getType();
	std::cout << "The dog COPY constructor called" << std::endl;
};

Dog::~Dog()
{
	std::cout << "what a productive day of sleeping, barking, pooping and eating" << std::endl;
};

std::string const &Dog::getType() const
{
	return (this->type);
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

Cat::Cat(std::string &type)
{
	this->type = type;
	std::cout << "The Cat PARA constructor called" << std::endl;
};

Cat::Cat(Cat const &copy)
{
	this->type = copy.getType();
	std::cout << "The cat COPY constructor called" << std::endl;
};

Cat::~Cat()
{
	std::cout << "8/9 cat's lives left" << std::endl;
};

std::string const &Cat::getType() const
{
	return (this->type);
};

void Cat::setType(std::string &type)
{
	this->type = type;
};

void Cat::makeSound() const
{
	std::cout << "Meow what you looking at Meow" << std::endl;
};
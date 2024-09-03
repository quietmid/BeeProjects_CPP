
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Chimera";
	std::cout << "The WrongAnimal default constructor is called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string &type)
{
	this->type = type;
	std::cout << "The WrongAnimal PARA constructor is called" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const &type)
{
	this->type = type.getType();
	std::cout << "The WrongAnimal COPY constructor is called" << std::endl;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "The WrongAnimal destructor is called" << std::endl;
};

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "Operator = called" << std::endl;
	this->type = copy.getType();
	return (*this);
};

std::string const &WrongAnimal::getType() const
{
	return (this->type);
};

void WrongAnimal::setType(std::string &type)
{
	this->type = type;
};

void WrongAnimal::makeSound() const
{
	std::cout << "pika pika" << std::endl;
};

// WrongCat
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "The WrongCat constructor called" << std::endl;
};

WrongCat::WrongCat(std::string &type)
{
	this->type = type;
	std::cout << "The WrongCat PARA constructor called" << std::endl;
};

WrongCat::WrongCat(WrongCat const &copy)
{
	this->type = copy.getType();
	std::cout << "The WrongCat COPY constructor called" << std::endl;
};

WrongCat::~WrongCat()
{
	std::cout << "The WrongCat destructor is called" << std::endl;
};


std::string const &WrongCat::getType() const
{
	return (this->type);
};

void WrongCat::setType(std::string &type)
{
	this->type = type;
};

void WrongCat::makeSound() const
{
	std::cout << "kot kot" << std::endl;
};	
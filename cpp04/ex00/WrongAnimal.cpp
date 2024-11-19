
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Chimera";
	std::cout << "The WrongAnimal default constructor is called" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const &type)
{
	*this = type;
	std::cout << "The WrongAnimal copy constructor is called" << std::endl;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "The WrongAnimal destructor is called" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy) {
		this->type = copy.getType();
		std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	}
	return (*this);
};

std::string const &WrongAnimal::getType() const
{
	return (this->type);
};

void WrongAnimal::makeSound() const
{
	std::cout << "pika pika" << std::endl;
};
	
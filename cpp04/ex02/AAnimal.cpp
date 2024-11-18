#include "AAnimal.hpp"

//Animal
AAnimal::AAnimal()
{
	this->type = "Manse";
	std::cout << "The AAnimal default constructor is called" << std::endl;
};

AAnimal::AAnimal(std::string &type)
{
	this->type = type;
	std::cout << "The Animal parametric constructor is called" << std::endl;
};

AAnimal::AAnimal(AAnimal const &type)
{
	*this = type;
	std::cout << "The AAnimal COPY constructor is called" << std::endl;
};

AAnimal::~AAnimal()
{
	std::cout << "The Animal destructor is called" << std::endl;
};

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
	if (this != &copy) {
		this->type = copy.getType();
		std::cout << "Animal copy assignment operator called" << std::endl;
	}
	return (*this);
};

void AAnimal::makeSound() const
{
	std::cout << "mitä mitä?" << std::endl;
};

std::string const &AAnimal::getType() const
{
	return (this->type);
};

void AAnimal::setType(std::string &type)
{
	this->type = type;
};

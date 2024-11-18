#include "Dog.hpp"
//constructors & destructor
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "The DAWG default constructor called" << std::endl;
};

Dog::Dog(std::string &type)
{
	this->type = type;
	std::cout << "The DAWG parametric constructor called" << std::endl;
};

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << "The DAWG copy constructor called" << std::endl;
};

Dog::~Dog()
{
	delete this->brain;
	std::cout << "what a productive day of sleeping, barking, pooping and eating" << std::endl;
};

//Assignment operator
Dog &Dog::operator=(Dog const &copy)
{
    if (this != &copy) {
        this->type = copy.getType();
		delete brain; //delete the old brain to prevent memory leaks
		this->brain = new Brain(*copy.brain);
    	std::cout << "Dawg copy assignment operator called" << std::endl;
    }
    return (*this);
};

//Member func
void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
};

void Dog::setIdea(int index, std::string idea)
{
	this->brain->setIdea(index, idea);
};

std::string Dog::getIdea(int index) const
{
	return (this->brain->getIdea(index));
};
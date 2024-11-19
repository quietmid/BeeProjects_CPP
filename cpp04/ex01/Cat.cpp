#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "The Cat default constructor called" << std::endl;
};


Cat::Cat(Cat const &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
	// *this = copy;
	std::cout << "The cat COPY constructor called" << std::endl;
};

Cat::~Cat()
{
	delete this->brain;
	std::cout << "8/9 cat's lives left" << std::endl;
};
//assignment operator
Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy) {
		this->type = copy.getType();
		delete this->brain; //delete the old brain to prevent memory leaks
		this->brain = new Brain(*copy.brain);
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
;}

//member func
void Cat::makeSound() const
{
	std::cout << "Meow what you looking at Meow" << std::endl;
};

void Cat::setIdea(int index, std::string idea)
{
	this->brain->setIdea(index, idea);
};

std::string Cat::getIdea(int index) const
{
	return (this->brain->getIdea(index));
};
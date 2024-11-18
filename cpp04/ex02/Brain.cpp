#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor gave you 10 points of IQ" << std::endl;
};

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain Copy Constructor your IQ goes up by 2%" << std::endl;
};

Brain::~Brain()
{
	std::cout << "Brain Destructor says you just lost 10 points of IQ" << std::endl;
};

Brain& Brain::operator=(const Brain &copy)
{
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.getIdea(i);
		std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return (*this);
};

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100) {
		std::cout << "can't think of that" << std::endl;
		return ("");
	}
	else 
		return (this->ideas[index]);
};

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100) {
		std::cout << "can't learn this trick" << std::endl;
		return ;
	}
	else {
		this->ideas[index] = idea;
	}
};
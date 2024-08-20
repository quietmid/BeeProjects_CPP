
#include "Zombie.hpp"

Zombie::Zombie(std::string zname)
{
	this->name = zname;
};

Zombie::~Zombie()
{
	std::cout << "It is your turn for next life, " << this->name << ", you get to be a golden retriever for a rich family in Malibu" << std::endl;
};

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
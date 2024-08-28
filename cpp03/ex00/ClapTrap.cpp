
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "a wild ClapTrap has appeared" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been disarmed" << std::endl;
};

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->dmg = 0;
	std::cout << "ClapTrap " << this->name << " is born! I am here to clap you" << std::endl;
};

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->ep -= 1;
	if (this->ep <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!, shutting down" << std::endl;
		delete this;
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
	if (this->hp <= 0)
		delete this;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	this->ep -= 1;
};

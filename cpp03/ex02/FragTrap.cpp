
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
	std::cout << "FragTrap " << this->name << " has been summoned!" << std::endl;
};

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap copy constructor called for " << this->name << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->name << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy) // check for self-assignment
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
		std::cout << "FragTrap copy assignment operator called for " << this->name << std::endl;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " is asking for a high five!" << std::endl;
};


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
	if (this->hp > 0 && this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
		this->ep -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " can't attack because it has no HP/EP" << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
	}
};

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	this->hp += amount;
	this->ep -= 1;
};

void ClapTrap::setDmg(int dmg)
{
	this->dmg = dmg;
	std::cout << "The damage is set to " << this->dmg << std::endl;
};

int ClapTrap::getEp() const
{
	return (this->ep);
};

int ClapTrap::getHp() const
{
	return (this->hp);
};

int ClapTrap::getDmg() const
{
	return (this->dmg);
};

std::string ClapTrap::getName() const
{
	return (this->name);
};

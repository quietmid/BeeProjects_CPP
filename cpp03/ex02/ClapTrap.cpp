
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hp = 10;
	this->ep = 10;
	this->dmg = 0;
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

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap " << this->name << " is born! I am here to clap you" << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) 
{
	if (this != &copy) // check for self-assignment
	{
        this->name = copy.name;
        this->hp = copy.hp;
        this->ep = copy.ep;
        this->dmg = copy.dmg;
        std::cout << "ClapTrap copy assignment operator called for " << this->name << std::endl;
    }
    return *this;
}


void ClapTrap::attack(std::string const &target)
{
	if (this->hp > 0 && this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
		this->ep -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is out of health point/energy!, shutting down" << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;

	if (this->hp > amount) 
	{
		this->hp -= amount;
	} 
	else
	{
		this->hp = 0;
	}
	if (this->hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
	}
};

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
		this->hp += amount;
		this->ep -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	}
};

void ClapTrap::setDmg(unsigned int dmg)
{
	this->dmg = dmg;
	std::cout << "The damage is set to " << this->dmg << std::endl;
};

unsigned int ClapTrap::getEp() const
{
	return (this->ep);
};

unsigned int ClapTrap::getHp() const
{
	return (this->hp);
};

std::string ClapTrap::getName() const
{
	return (this->name);
};

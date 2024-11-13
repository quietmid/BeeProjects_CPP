
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap()
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	this->gateKeeperMode = false;
	std::cout << "a wild ScavTrap has appeared" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	this->gateKeeperMode = false;
	std::cout << "ScavTrap " << this->name << " is born! why was I born?" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is now destoryed" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy) // check for self-assignment
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->dmg = copy.dmg;
		std::cout << "ScavTrap copy assignment operator called for " << this->name << std::endl;
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->hp > 0 && this->ep > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
		this->ep -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " can't attack because it's demure" << std::endl;
	}
};

void ScavTrap::guardGate()
{
	if (this->gateKeeperMode == false)
	{
		std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
		this->gateKeeperMode = true;
	}
	else
	{
		this->gateKeeperMode = false;
		std::cout << "ScavTrap " << this->name << " is leaving in Gate keeper mode" << std::endl;
		return ;
	}
};

void ScavTrap::getGateKeeperMode() const
{
	if (this->gateKeeperMode == true)
		std::cout << "ScavTrap " << this->name << " is in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not in Gate keeper mode" << std::endl;
};
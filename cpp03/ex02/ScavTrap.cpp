
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap()
{
	std::cout << "a wild ScavTrap has appeared" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->name = copy.name;
	this->hp = copy.hp;
	this->ep = copy.ep;
	this->dmg = copy.dmg;
	this->gateKeeperMode = 0;
	std::cout << "ScavTrap copy constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	std::cout << "ScavTrap " << this->name << " is born! I am here to ... here to ... :3 " << std::endl;
};
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is now destoryed" << std::endl;
};

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
	if (this->gateKeeperMode == 0)
	{
		std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
};
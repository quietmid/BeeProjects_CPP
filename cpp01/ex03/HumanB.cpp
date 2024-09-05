
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << this->name << " is born!" << std::endl;
};

HumanB::~HumanB()
{
	std::cout << "HumanB destructer called" << std::endl;
};

void HumanB::setWeapon(Weapon& weapon) 
{
	this->weapon = &weapon;
	std::cout << this->name << " pick up a " << weapon.getType() << std::endl;
};
void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
};
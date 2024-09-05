#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	this->name = name;
	std::cout << this->name << "is born with a " << weapon.getType() << " in their hands" << std::endl;
};

HumanA::~HumanA()
{
	std::cout << "Human A destructor called" << std::endl;
};

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
};
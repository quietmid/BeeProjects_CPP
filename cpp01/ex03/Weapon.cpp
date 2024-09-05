
#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_name)
{
	this->type = weapon_name;
};

Weapon::Weapon()
{
	
};
Weapon::~Weapon()
{

};

std::string Weapon::getType() const
{
	return (this->type);
};

void	Weapon::setType(std::string type)
{
	this->type = type;
	std::cout << "weapon type set to " << this->type << std::endl;
}
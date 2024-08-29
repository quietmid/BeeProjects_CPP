
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap _new = ClapTrap("Ninja");
	
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	_new.attack("poor people");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	_new.takeDamage(11);
	_new.attack("more poor people");
	_new.beRepaired(5);
	_new.setDmg(3);
	_new.attack("more poor people");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	return 0;
};
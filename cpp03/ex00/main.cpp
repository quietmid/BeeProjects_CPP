
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap _new = ClapTrap("Ninja");
	// ClapTrap _new2 = ClapTrap();
	
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	_new.attack("poor people");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	_new.takeDamage(11);
	// _new2.takeDamage(5);
	// std::cout << "new2's hp is " << _new2.getHp() << std::endl;
	std::cout << _new.getName() << "'s health is " << _new.getHp() << std::endl;
	_new.attack("more poor people");
	_new.beRepaired(5);
	_new.setDmg(3);
	_new.attack("more poor people");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	return 0;
};
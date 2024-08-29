
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap _new = ClapTrap("Ninja");
	ScavTrap _new2 = ScavTrap("Rogue");
	FragTrap a;
	FragTrap b("Roger");
	
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEp() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEp() << std::endl;
	std::cout << std::endl;
	_new.attack("rich people");
	_new2.attack("rich people twice");
	a.attack("wealth people");
	b.attack("wealth people twice");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEp() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEp() << std::endl;
	std::cout << std::endl;
	_new.takeDamage(11);
	_new2.takeDamage(125);
	a.takeDamage(5);
	b.takeDamage(150);
	_new.attack("more poor people");
	_new2.attack("more poor people");
	a.attack("poor people's dogs");
	b.attack("poor people's cats");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEp() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEp() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	_new.beRepaired(5);
	_new2.beRepaired(75);
	a.beRepaired(5);
	b.beRepaired(75);
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEp() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEp() << std::endl;
	std::cout << std::endl;
	_new.setDmg(3);
	_new2.setDmg(40);
	_new.attack("more poor people");
	_new2.attack("more poor people");
	std::cout << std::endl;
	_new2.guardGate();
	b.highFivesGuys();
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEp() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEp() << std::endl;
	std::cout << std::endl;
	return 0;
};
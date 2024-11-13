
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int main()
{
	ClapTrap _new = ClapTrap("Ninja");
	ScavTrap _new2 = ScavTrap("Rogue");
	
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << std::endl;
	_new.attack("rich people");
	_new2.attack("rich people twice");
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	_new.takeDamage(10);
	_new2.takeDamage(102);
	_new.attack("more poor people");
	_new2.attack("more poor people");
	std::cout << _new.getName() << "'s health is " << _new.getHp() << std::endl;
	std::cout << _new2.getName() << "'s health is " << _new2.getHp() << std::endl;
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << std::endl;
	_new.beRepaired(5);
	_new2.beRepaired(75);
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	std::cout << _new.getName() << "'s health is " << _new.getHp() << std::endl;
	std::cout << _new2.getName() << "'s health is " << _new2.getHp() << std::endl;
	_new.setDmg(3);
	_new2.setDmg(40);
	_new.attack("more poor people");
	_new2.attack("more poor people");
	std::cout << std::endl;
	_new2.guardGate();
	_new2.guardGate();
	_new2.getGateKeeperMode();
	std::cout << _new.getName() << "'s energy points: " << _new.getEp() << std::endl;
	std::cout << _new2.getName() << "'s energy points: " << _new2.getEp() << std::endl;
	return 0;
};
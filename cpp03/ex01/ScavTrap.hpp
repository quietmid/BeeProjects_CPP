#pragma once

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

// this is how you inherit from another class
class ScavTrap : public ClapTrap
{
	private:
		bool gateKeeperMode;
	public:
	// constructor & destructor	
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

	//assignement operator
		ScavTrap& operator=(const ScavTrap &copy);
	
	// functions
		void attack(std::string const &target);
		void guardGate();
	//getter
		void getGateKeeperMode() const;
};
/*
virtual functions in the base class allows the derived class to override the methods in the base class
override functions in the derived class ensures that the method is correctly overriding a virutal method from the base class, providing compile-time safety.
In C++, the compiler uses the function signature to determine which virtual function is being overridden. The function signature includes the function name, the parameter types, and the const-qualification (if any).
*/
#endif
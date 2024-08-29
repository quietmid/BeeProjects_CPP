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
		int gateKeeperMode;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		~ScavTrap();
		void attack(std::string const &target);
		void guardGate();
};

#endif
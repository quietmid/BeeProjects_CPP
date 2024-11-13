#pragma once

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	//constructors & destructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

	//assignment operator
		FragTrap& operator=(const FragTrap &copy);
	//functions
		void highFivesGuys(void);
};

#endif
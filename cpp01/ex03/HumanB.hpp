
#pragma once

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string name;
	public:
		Weapon* weapon;
		HumanB(std::string name);
		~HumanB();
		// action
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
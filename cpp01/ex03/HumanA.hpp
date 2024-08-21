
#pragma once

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		Weapon& weapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon& Weapon);
		~HumanA();
		// action
		void attack();
};

#endif

#pragma once

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string weapon_name);
		Weapon();
		~Weapon();
		// Getters
		std::string getType() const;
		// Setters
		void setType(std::string type);
};

#endif
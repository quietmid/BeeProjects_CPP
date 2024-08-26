

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(); // default constructor so we can use to create an array of Zombie object
		~Zombie(); // destructor
		Zombie(std::string zname); //parameterized constructor, used to initialize objects with specific values.
		void announce();
		void setName(std::string zname);
};

// returns pointer to the new Zombie object on the heap
Zombie *newZombie(std::string name);

// creates a new Zombie object on the stack
void	randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif


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
		Zombie(std::string zname);
		~Zombie();
		void announce();
};

// returns pointer to the new Zombie object on the heap
Zombie *newZombie(std::string name);

// creates a new Zombie object on the stack
void	randomChump(std::string name);

#endif

// stack: local variables and is automatically destroyed when the function exists
// heap: manually managed by using new() and delete
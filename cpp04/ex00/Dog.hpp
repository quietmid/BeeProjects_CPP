#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string> 
#include "Animal.hpp"

class Dog : public Animal
{

	public:
		//Constructor, Destructor, Copy Constructor
		Dog();
		Dog(std::string &type);
		Dog(Dog const &copy);
		~Dog();

        //Assignment operator
        Dog &operator=(Dog const &copy);

		//member func
		void makeSound() const;
};

#endif
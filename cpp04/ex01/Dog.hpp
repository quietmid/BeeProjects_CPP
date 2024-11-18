#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string> 
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		//Constructor, Destructor, Copy Constructor
		Dog();
		Dog(std::string &type);
		Dog(Dog const &copy);
		~Dog();

        //Assignment operator
        Dog &operator=(Dog const &copy);

		//member func
		void makeSound() const override;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif
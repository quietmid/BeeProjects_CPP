#pragma once

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>

// main class Animal
class Animal
{
	protected:
		std::string type;
	public:
		//Constructor, Destructor, Copy Constructor
		Animal();
		Animal(std::string &type);
		Animal(Animal const &copy);
		virtual ~Animal();

		//assignment operator
		Animal& operator=(const Animal &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		virtual void makeSound() const;
};

#endif
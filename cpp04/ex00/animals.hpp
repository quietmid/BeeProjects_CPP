#pragma once

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>
#include "animals.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		//Constructor, Destructor, Copy Constructor
		Animal();
		virtual ~Animal();
		Animal const &operator=(Animal const &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		virtual void makeSound() const;
};

class Dog : public Animal
{

	public:
		//Constructor, Destructor, Copy Constructor
		Dog();
		Dog(std::string &type);
		~Dog();
		//setter & getter
		void setType(std::string &type);
		//member func
		void makeSound() const;
};

class Cat : public Animal
{
	public:
		//Constructor, Destructor, Copy Constructor
		Cat();
		~Cat();
		//setter & getter
		void setType(std::string &type);
		//member func
		void makeSound() const;
};



#endif
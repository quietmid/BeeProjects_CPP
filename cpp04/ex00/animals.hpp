#pragma once

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>
#include "animals.hpp"

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
		Animal const &operator=(Animal const &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		virtual void makeSound() const;
};
// Dog
class Dog : public Animal
{

	public:
		//Constructor, Destructor, Copy Constructor
		Dog();
		Dog(std::string &type);
		Dog(Dog const &copy);
		~Dog();
		//setter & getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		void makeSound() const;
};

// Cat
class Cat : public Animal
{
	public:
		//Constructor, Destructor, Copy Constructor
		Cat();
		Cat(std::string &type);
		Cat(Cat const &copy);
		~Cat();
		//setter & getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		void makeSound() const;
};

#endif
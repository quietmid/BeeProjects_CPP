#pragma once

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		void makeSound();
};

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		void makeSound();
};

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		void makeSound();
};



#endif
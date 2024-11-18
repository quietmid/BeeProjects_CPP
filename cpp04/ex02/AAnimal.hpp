#pragma once

#ifndef AANIMALS_HPP
#define AANIMALS_HPP

#include <iostream>
#include <string>

// main class Animal
class AAnimal
{
	protected:
		std::string type;
	public:
		//Constructor, Destructor, Copy Constructor
		AAnimal();
		AAnimal(std::string &type);
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal();

		//assignment operator
		AAnimal& operator=(const AAnimal &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		virtual void makeSound() const = 0;
		// by having one pure virutal function, this class becomes abstract
};

#endif
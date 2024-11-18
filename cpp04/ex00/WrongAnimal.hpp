
#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		//Constructor, Destructor, Copy Constructor
		WrongAnimal();
		WrongAnimal(std::string &type);
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal();
		//Assignment Operator
		WrongAnimal &operator=(WrongAnimal const &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		// member func
		void makeSound() const;
};

#endif
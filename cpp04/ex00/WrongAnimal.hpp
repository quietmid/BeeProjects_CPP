
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
		virtual ~WrongAnimal();
		WrongAnimal const &operator=(WrongAnimal const &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		// member func
		virtual void makeSound() const;
};

#endif
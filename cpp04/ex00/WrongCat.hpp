#pragma once

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//Constructor, Destructor, Copy Constructor
		WrongCat();

		WrongCat(WrongCat const &copy);
		~WrongCat();
		//Assignment Operator
		WrongCat &operator=(const WrongCat &copy);
		//member func
		void makeSound() const;
};

#endif
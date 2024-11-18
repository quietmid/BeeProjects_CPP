#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		//Constructor, Destructor, Copy Constructor
		Cat();
		Cat(std::string &type);
		Cat(Cat const &copy);
		~Cat();

        //Assignment operator
		Cat& operator=(const Cat &copy);
		//member func
		void makeSound() const override;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif
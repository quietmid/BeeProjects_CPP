
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
		WrongAnimal const &operator=(WrongAnimal const &copy);
		//setter and getter
		std::string const &getType() const;
		void setType(std::string &type);
		// member func
		virtual void makeSound() const;
};


class WrongCat : public WrongAnimal
{
	public:
		//Constructor, Destructor, Copy Constructor
		WrongCat();
		WrongCat(std::string &type);
		WrongCat(WrongCat const &copy);
		~WrongCat();
		//setter & getter
		std::string const &getType() const;
		void setType(std::string &type);
		//member func
		void makeSound() const;
};

#endif
#pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		//constructor, destructor, copy constructor
		Brain();
		Brain(const Brain &copy);
		~Brain();
		
		//assignment operator
		Brain& operator=(const Brain &copy);

		//setter and getter
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif
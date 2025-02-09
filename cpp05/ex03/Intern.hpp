#pragma once

#include <iostream>
#include <map>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	private:
		std::map<std::string, AForm* (*)(std::string)> formCreate;
		//parameter constructor here
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(const Intern &copy);
		AForm* makeForm(std::string formName, std::string target);
};
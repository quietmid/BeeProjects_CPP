#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	private:
		std::string _forms[3];
		AForm* (Intern::*_formCreate[3])(std::string target);

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(const Intern &copy);
		AForm* makeForm(std::string formName, std::string target);

		AForm* makeShrubbery(std::string target);
		AForm* makeRobotomy(std::string target);
		AForm* makePresidential(std::string target);
};
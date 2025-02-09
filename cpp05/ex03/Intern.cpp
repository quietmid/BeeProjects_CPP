#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Intern Default Constructor Called" << std::endl;
	formCreate["Shrubbery Creation Form"] = [](std::string target) -> AForm* { return new ShrubberyCreationForm(target); };
	formCreate["Robotomy Request Form"] = [](std::string target) -> AForm* { return new RobotomyRequestForm(target); };
	formCreate["Presidential Pardon Form"] = [](std::string target) -> AForm* { return new PresidentialPardonForm(target); };
}

Intern::Intern(const Intern &copy)
{
	// std::cout << "Intern Copy Constructor Called but there is nothing to copy" << std::endl;
	(void)copy;
}

Intern::~Intern()
{
	// std::cout << "Intern Destructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern &copy)
{
	// std::cout << "Intern Assignation Operator Called" << std::endl;
	(void)copy;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::map<std::string, AForm* (*)(std::string)>::iterator form = formCreate.find(formName);
	if (form != formCreate.end())
	{
		std::cout << "Intern creates " << formName << std::endl;
		return form->second(target);
	}
	else
	{
		std::cout << "Error: Form: " << formName << " can't be found" <<std::endl;
		return NULL;
	}
}
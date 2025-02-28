#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Intern Default Constructor Called" << std::endl;
	_forms[0] = "Shrubbery Creation Form";
	_forms[1] = "Robotomy Request Form";
	_forms[2] = "Presidential Pardon Form";

	_formCreate[0] = &Intern::makeShrubbery;
	_formCreate[1] = &Intern::makeRobotomy;
	_formCreate[2] = &Intern::makePresidential;
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
	AForm* form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
		{
			form = (this->*_formCreate[i])(target);
			std::cout << "Intern creates " << formName << std::endl;
		}
	}
	if (!form)
		std::cout << "Error: Form: " << formName << " can't be found" <<std::endl;
	return form;
}

AForm* Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}
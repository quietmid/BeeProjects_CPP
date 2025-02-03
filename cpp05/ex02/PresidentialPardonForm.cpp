#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	//std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	//std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm destructor" << std::endl;
}
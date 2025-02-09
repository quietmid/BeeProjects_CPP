#pragma once

#include "AForm.hpp"

class PresidentialPardonForm :  public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm() override;
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);

		void executeAction() const override; 
};
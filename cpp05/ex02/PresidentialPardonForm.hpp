#pragma once

#include "AForm.hpp"

class PresidentialPardonForm :  public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm() override;
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);

		void execute(Bureaucrat const & executor) const override; 
		//tells us <target> has been pardoned by Zaphod Beeblebrox
};
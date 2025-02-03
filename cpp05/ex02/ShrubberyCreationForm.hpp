#pragma once

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm() override;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);

		void execute(Bureaucrat const & executor) const override; 
		//creates a file <target>_shrubbery, and writes ASCII trees inside it, in the current directory
};
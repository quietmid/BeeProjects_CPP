#pragma once

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm() override;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);

		void executeAction() const override; 
};
#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm() override;
		RobotomyRequestForm& operator=(const RobotomyRequestForm &copy);

		void execute(Bureaucrat const & executor) const override; 
		//robotomizes the target, with a 50% chance of success. 
		//If it fails, throw an exception, if it succeeds, print some drilling noises

};
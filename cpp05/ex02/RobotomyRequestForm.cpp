#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	// std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm Parameter Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
	// std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Robotomizing has a 50 percent chance of success" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed!" << std::endl;
}
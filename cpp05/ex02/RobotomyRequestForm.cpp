#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default") {
	// std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm Parameter Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
	// std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {
		_target = copy._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction() const 
{
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Robotomizing has a 50 percent chance of success" << std::endl;
	int r = rand(); // this extra step is for debugging
	// std::cout << "random num is: " << r << std::endl; 
	if (r %= 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed!" << std::endl;
}
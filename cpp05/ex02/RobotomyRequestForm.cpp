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
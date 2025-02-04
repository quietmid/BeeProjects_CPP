#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // check if AForm is abstract, can it be instantiated?
    // AForm form;
    // AForm form("Form", 1, 1);
    // check if ShrubbberyCreationForm is concrete and it can be instantiated?

    std::cout << "-----ShrubberyCreationForm-----" << std::endl;
    Bureaucrat john("John", 139);
    ShrubberyCreationForm shrubbery("garden");
    shrubbery.beSigned(john);
    john.executeForm(shrubbery);
    john.gradeGoUp();
    john.gradeGoUp();
    john.executeForm(shrubbery);
    std::cout << "-----RobotomyRequestnForm-----" << std::endl;
    Bureaucrat jane("Jane", 43);
    RobotomyRequestForm robot("robot");
    robot.beSigned(jane);
    jane.executeForm(robot);
    std::cout << "-----PresidentialPardonForm-----" << std::endl;
    Bureaucrat donald("Trumpf",7);
    PresidentialPardonForm pardon("felonies");
    pardon.beSigned(donald);
    donald.executeForm(pardon);
    return 0;
}
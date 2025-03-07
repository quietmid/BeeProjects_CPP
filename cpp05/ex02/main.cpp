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
    srand(time(0));
try {
        std::cout << YELLOW_BG << "-----ShrubberyCreationForm-----" << RESET << std::endl;
        Bureaucrat john("John", 139);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << shrubbery;
        john.signForm(shrubbery);
        john.executeForm(shrubbery);
        john.gradeGoUp();
        john.gradeGoUp();
        john.executeForm(shrubbery);
        std::cout << YELLOW_BG << "-----RobotomyRequestnForm-----" << RESET << std::endl;
        Bureaucrat jane("Jane", 55);
        std::cout << jane << std::endl;
        Bureaucrat robert("Robert", 35);
        std::cout << robert << std::endl;
        RobotomyRequestForm robot("robot");
        RobotomyRequestForm robot2("robot2");
        std::cout << robot2 << std::endl;
        std::cout << robot;
        jane.signForm(robot);
        jane.signForm(robot2);
        jane.executeForm(robot);
        jane.executeForm(robot2);
        std::cout << YELLOW_BG << "     ---- but Robert has a higher grade ----" << RESET << std::endl;
        robert.executeForm(robot);
        robert.executeForm(robot2);
        std::cout << YELLOW_BG << "-----PresidentialPardonForm-----" << RESET << std::endl;
        Bureaucrat donald("Trumpf", 7);
        std::cout << donald << std::endl;
        PresidentialPardonForm pardon("felonies");
        std::cout << pardon;
        donald.signForm(pardon);
        donald.executeForm(pardon);
        Bureaucrat pence("dad", 3);
        std::cout << pence << std::endl;
        pence.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } 
    return 0;
}
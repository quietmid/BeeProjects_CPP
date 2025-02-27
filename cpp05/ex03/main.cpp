#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try {
        Intern jeremy;
        AForm *form;
        AForm *form2;
        Bureaucrat john("John", 135);
        Bureaucrat jeff("Jeff", 43);
        std::cout << YELLOW_BG << "   ----- a wild intern apeared and trying to make form -----  " << RESET << std::endl;
        form = jeremy.makeForm("Shrubbery Creation Form", "home");
        form2 = jeremy.makeForm("Visa Request Form", "robot");
        form2 = jeremy.makeForm("Robotomy Request Form", "robot");
        std::cout << YELLOW_BG << "   ----- John and Jeff signing forms attempt 1 -----  " << RESET << std::endl;
        john.signForm(*form2);
        jeff.signForm(*form);
        std::cout << YELLOW_BG << "   ----- John and Jeff signing forms attempt 2 -----  " << RESET << std::endl;
        john.signForm(*form);
        jeff.signForm(*form2);
        std::cout << YELLOW_BG << "   ----- John and Jeff executing forms -----  " << RESET << std::endl;
        john.executeForm(*form);
        jeff.executeForm(*form2);
        delete form;
        delete form2;
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
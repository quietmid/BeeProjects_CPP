#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    // check if AForm is abstract, can it be instantiated?
    // AForm form;
    // AForm form("Form", 1, 1);
    // check if ShrubbberyCreationForm is concrete and it can be instantiated?

    std::cout << "-----ShrubberyCreationForm-----" << std::endl;
    Bureaucrat john("John", 45);
    ShrubberyCreationForm shrubbery("garden");
    shrubbery.execute(john);

    return 0;
}
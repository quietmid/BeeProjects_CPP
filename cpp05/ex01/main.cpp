#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "-------testing Bob-------" << std::endl;
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
		bob.gradeGoUp();
        std::cout << bob << std::endl;
        Form a;
        bob.signForm(a);
		std::cout << "-------testing Alice-------" << std::endl;
        Bureaucrat alice("Alice", 0); // This will throw an exception
        std::cout << alice << std::endl;
        std::cout << "-------testing Charlie-------" << std::endl; // be skipped because of the exception
        Bureaucrat charlie("Charlie", 140);
        std::cout << charlie << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try{
        //no exception here
        std::cout << "-------testing Form-------" << std::endl;
        Bureaucrat john("John", 15);
        Form sheet("FormA", 25, 50);
        std::cout << john << std::endl;
        john.gradeGoDown();
        std::cout << john << std::endl;
        sheet.beSigned(john);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << "------- testing Form with exception ------" << std::endl;
        Bureaucrat law("Law", 75);
        Form b("your life", 15, 75);
        std::cout << law << std::endl;
        std::cout << law.getName() << " trying to get the " << b.getName() << " to be signed... can he though?" << std::endl; 
        b.beSigned(law);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "----------- More testing ------------" << std::endl;
        Bureaucrat cey("Cece", 60);
        Form c("legal rights", 20, 75);
        std::cout << c;
        cey.signForm(c);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
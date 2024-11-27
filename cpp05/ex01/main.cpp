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
        std::cout << "-------testing Bob2-------" << std::endl;
        Bureaucrat bob2("Bob2", 25);
        std::cout << bob2 << std::endl;
        bob2.gradeGoDown();
        std::cout << bob2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
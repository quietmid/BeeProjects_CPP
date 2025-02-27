#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "-------testing Bob-------" << std::endl;
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
		bob.gradeGoUp();
        std::cout << bob << std::endl;
		std::cout << "-------testing Alice-------" << std::endl;
        Bureaucrat alice("Alice", 0); // This will throw an exception
        std::cout << alice << std::endl;
        std::cout << "-------testing Charlie-------" << std::endl;
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
        std::cout << bob2 << ", is a hardworking bureaucrat!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << "-------testing Bob3-------" << std::endl;
        Bureaucrat bob3("Bob3", 150);
        std::cout << bob3 << std::endl;
        bob3.gradeGoDown();
        std::cout << bob3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << "-------testing Bob4-------" << std::endl;
        Bureaucrat bob4("Bob4", 1);
        std::cout << bob4 << std::endl;
        bob4.gradeGoUp();
        std::cout << bob4 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
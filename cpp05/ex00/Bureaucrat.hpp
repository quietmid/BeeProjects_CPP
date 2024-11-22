#pragma once

#include <iostream>
#include <string>
#include <exception>

#define EXCEPTION_TOO_HIGH "Grade is too high! The highest grade is 1."
#define EXCEPTION_TOO_LOW "Grade is too low! The lowest grade is 150."

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		Bureaucrat(); // putting the default constructor in private to prevent the user from using it
	public:
		//constructor, destructor, copy constructor
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		//assignment operator
		Bureaucrat& operator=(const Bureaucrat &copy);
		//setter and getter
		std::string getName() const;
		int getGrade() const;

		// functions
		void gradeGoUp();
		void gradeGoDown();

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return EXCEPTION_TOO_HIGH;
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return EXCEPTION_TOO_LOW;
				}
		};
};


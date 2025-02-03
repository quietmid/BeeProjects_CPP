#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define EXCEPTION_TOO_HIGH "Grade is too high! The highest grade is 1."
#define EXCEPTION_TOO_LOW "Grade is too low! The lowest grade is 150."

class AForm;

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
		void signForm(AForm f);

		// Exception classes
		/* what() is a member func of std::exception and with the override keyword, it overrides the what() with the either of these exception

		the noexcept specifier indicates that this func won't throw any exception
		*/
	
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return EXCEPTION_TOO_HIGH;
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return EXCEPTION_TOO_LOW;
				}
		};
};
//overload the << operator

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);


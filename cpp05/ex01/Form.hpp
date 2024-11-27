#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		//constructor, destructor, copy constructor
		Form();
		Form(const Form &copy);
		~Form();
		//assignement operator
		Form& operator=(const Form &copy);
		//setter and getter
		std::string getName() const;
		bool getSigned() const;
		//functions
		void beSigned(const Bureaucrat &b);
		//Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return "Grade is too high! The highest grade is 1.";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return "Grade is too low! The lowest grade is 150.";
				}
		};
};

// std::ostream& operator<<(std::ostream &out, const Form &f);
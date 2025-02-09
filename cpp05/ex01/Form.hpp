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
		Form();
	public:
		//constructor, destructor, copy constructor
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &copy);
		~Form();
		//assignement operator
		Form& operator=(const Form &copy);
		//setter and getter
		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExecuteGrade() const;

		//functions
		void beSigned(const Bureaucrat &b);
		//Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return "Grade is too high to be signed?";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return "Grade is too low, what were you even thinking?";
				}
		};

	//the friend keyword, the operator<< function is allowed to access the private members of the Form class, so enable the function to print out all the info 
	friend std::ostream& operator<<(std::ostream &out, const Form &f);
};

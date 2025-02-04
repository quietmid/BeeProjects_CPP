#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		//constructor, destructor, copy constructor
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		//assignement operator
		AForm& operator=(const AForm &copy);
		//setter and getter
		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExecuteGrade() const;

		//functions
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const;
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const noexcept override {
					return "Form is not signed, cannot execute";
				}
		};

	//the friend keyword, the operator<< function is allowed to access the private members of the Form class, so enable the function to print out all the info 
	friend std::ostream& operator<<(std::ostream &out, const AForm &f);
};

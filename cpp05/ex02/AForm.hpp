#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define CYAN_BG "\033[46;30m"
# define YELLOW_BG "\033[103;30m"
# define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
		AForm();
	public:
		//constructor, destructor, copy constructor
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
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0; //pure virtual function
		
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

};

std::ostream& operator<<(std::ostream &out, const AForm &f);

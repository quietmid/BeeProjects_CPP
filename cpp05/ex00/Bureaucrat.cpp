#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	// std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	// std::cout << "Bureaucrat Param Constructor Called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	// std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat Destructor Called" << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		_grade = copy.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::gradeGoUp()
{
	std::cout << "Attempt to increase grade by 1pt" << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Grade up by 1 pt" << std::endl;
	_grade--;
}

void Bureaucrat::gradeGoDown()
{
	std::cout << "Attempt to decrease grade by 1pt" << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Grade down by 1 pt" << std::endl;
	_grade++;
}


std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) 
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
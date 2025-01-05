#include "Form.hpp"

Form::Form() : _name("Graduation slip"), _gradeToSign(1), _gradeToExecute(1)
{
	_signed = false;
	// std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_signed = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	// std::cout << "Form Param Constructor Called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	// std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Form Destructor Called" << std::endl;
}

Form& Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		_signed = copy._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

void Form::beSigned(const Bureaucrat &b)
{
	try 
	{
		if (b.getGrade() <= _gradeToSign)
		{
			_signed = true;
			std::cout << b.getName() << "'s " << _name << " just got signed!" << std::endl;
		}
		else
			throw Form::GradeTooLowException();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGrade() const
{
	return _gradeToSign;
}

int Form::getExecuteGrade() const
{
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream &out, const Form &f)
{
	out << "Form: " << f.getName() << " is " << (f.getSigned() ? "signed" : "not signed") << "/n"
		<< ", grade to sing: " << f.getGrade() << "/n"
		<< ", grade to execute:  " << f.getExecuteGrade() << std::endl;
	return out;
}

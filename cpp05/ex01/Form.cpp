#include "Form.hpp"

Form::Form() : _name("Graduation slip"), _gradeToSign(22), _gradeToExecute(150)
{
	_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	;
}

Form::~Form()
{
};

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
	if (b.getGrade() > 150)
		throw Form::GradeTooLowException();
	else if (b.getGrade() < 1)
		throw Form::GradeTooHighException();
	else if (b.getGrade() <= _gradeToSign)
		_signed = true;	
}

bool Form::getSigned() const
{
	return _signed;
}
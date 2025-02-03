#include "AForm.hpp"

AForm::AForm() : _name("Graduation slip"), _gradeToSign(1), _gradeToExecute(1)
{
	_signed = false;
	// std::cout << "Form Default Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_signed = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	// std::cout << "Form Param Constructor Called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	// std::cout << "Form Copy Constructor Called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "Form Destructor Called" << std::endl;
}

AForm& AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_signed = copy._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

void AForm::beSigned(const Bureaucrat &b)
{
	try 
	{
		if (b.getGrade() <= _gradeToSign)
		{
			_signed = true;
			std::cout << b.getName() << "'s " << _name << " just got signed!" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGrade() const
{
	return _gradeToSign;
}

int AForm::getExecuteGrade() const
{
	return _gradeToExecute;
}

void AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > _gradeToExecute && _signed)
			throw AForm::GradeTooLowException();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream &out, const AForm &f)
{
	out << "Form: " << f.getName() << " is " << (f.getSigned() ? "signed" : "not signed") << "/n"
		<< ", grade to sing: " << f.getGrade() << "/n"
		<< ", grade to execute:  " << f.getExecuteGrade() << std::endl;
	return out;
}

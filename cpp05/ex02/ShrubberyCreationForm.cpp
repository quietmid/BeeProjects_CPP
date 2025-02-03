#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
	// std::cout << "ShrubbberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	//std::cout << "Shrubbery Parameter Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	//std::cout << "Shrubbery Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubbberyCreationForm Destructor Called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)	const
{
	try
	{
		if (executor.getGrade() > getExecuteGrade() && getSigned() == false)
			throw AForm::GradeTooLowException();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	std::string filename = _target + "_shrubbery";

	std::ofstream myFile(filename);
	// myFile << "ASCII trees inside it, in the current directory" << std::endl;
	myFile.close();
}
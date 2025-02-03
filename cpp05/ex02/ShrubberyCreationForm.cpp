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
	try // need to add || getSigned == false
	{
		if (executor.getGrade() > getExecuteGrade())
			throw AForm::GradeTooLowException();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	std::string filename = _target + "_shrubbery";

	std::ofstream myFile(filename);
	myFile << "  ___" << std::endl;
	myFile << "_/  |________   ____   ____   ______" << std::endl;
	myFile << "\\   __\\_  __ \\_/ __ \\_/ __ \\ /  ___/" << std::endl;
	myFile << " |  |  |  | \\/\\  ___/\\  ___/ \\___ \\ " << std::endl;
	myFile << " |__|  |__|    \\___  >\\___  >____  >" << std::endl;
	myFile << "                   \\/     \\/     \\/ " << std::endl;

	myFile.close();
}
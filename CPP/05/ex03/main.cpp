#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat Billy("Billy", 1);
	Bureaucrat Philippe("Philippe", 150);
	Bureaucrat Billycpy(Billy);

	Intern Bob;

	try
	{
		AForm*	invalid = NULL;
		invalid = Bob.makeForm("FAILURE", "UI");
	}
	catch (std::exception& e)
	{
	}

	AForm*	robot = Bob.makeForm("robotomy request", "Jean");
	AForm*	shrub = Bob.makeForm("shrubbery creation", "ALED");
	AForm*	pardon = Bob.makeForm("presidential pardon", "Gazzo");

	std::cout << "Shrubbery form tests:" << std::endl << *shrub << std::endl << std::endl;

	Philippe.signForm(*shrub);
	Philippe.executeForm(*shrub);
	Billy.signForm(*shrub);
	Philippe.executeForm(*shrub);
	Billy.executeForm(*shrub);

	std::cout << std::endl << "Robotomy form tests:" << std::endl << *robot << std::endl << std::endl;

	Philippe.signForm(*robot);
	Philippe.executeForm(*robot);
	Billy.signForm(*robot);
	Philippe.executeForm(*robot);
	Billy.executeForm(*robot);

	std::cout << std::endl << "Presidential pardon form tests:" << std::endl << *pardon << std::endl << std::endl;

	Philippe.signForm(*pardon);
	Philippe.executeForm(*pardon);
	Billy.signForm(*pardon);
	Philippe.executeForm(*pardon);
	Billy.executeForm(*pardon);

	delete robot;
	delete shrub;
	delete pardon;

	return (0);
}
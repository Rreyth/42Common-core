#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Billy("Billy", 1);
	Bureaucrat Philippe("Philippe", 150);
	Bureaucrat Billycpy(Billy);

	ShrubberyCreationForm	shrubForm("HERE");
	RobotomyRequestForm		robotForm("Gazzo");
	PresidentialPardonForm	pardonForm("Myself");

	std::cout << "Shrubbery form tests:" << std::endl << shrubForm << std::endl << std::endl;

	Philippe.signForm(shrubForm);
	Philippe.executeForm(shrubForm);
	Billy.signForm(shrubForm);
	Philippe.executeForm(shrubForm);
	Billy.executeForm(shrubForm);

	std::cout << std::endl << "Robotomy form tests:" << std::endl << robotForm << std::endl << std::endl;

	Philippe.signForm(robotForm);
	Philippe.executeForm(robotForm);
	Billy.signForm(robotForm);
	Philippe.executeForm(robotForm);
	Billy.executeForm(robotForm);

	std::cout << std::endl << "Presidential pardon form tests:" << std::endl << pardonForm << std::endl << std::endl;

	Philippe.signForm(pardonForm);
	Philippe.executeForm(pardonForm);
	Billy.signForm(pardonForm);
	Philippe.executeForm(pardonForm);
	Billy.executeForm(pardonForm);

	return (0);
}
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Intern::Intern( void )
{

}


Intern::Intern(const Intern &obj)
{
	(void)obj;
}


Intern::~Intern( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Intern	&Intern::operator=(const Intern &obj)
{
	if (this == &obj)
		return (*this);

	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

AForm	*Intern::makeForm(std::string name, std::string target)
{
	const struct {
		std::string formName;
		AForm * (Intern::*formMaker)(std::string);
	} formMakers[3] = {
		{"robotomy request", &Intern::createRobot},
		{"shrubbery creation", &Intern::createShrubbery},
		{"presidential pardon", &Intern::createPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formMakers[i].formName)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*(formMakers[i].formMaker))(target));
		}
	}
	std::cout << "Form " << name << " does not exist" << std::endl;
	throw (std::invalid_argument(name));
}

AForm	*Intern::createRobot(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Default_Robotomy", 72, 45)
{
	_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target + "_Robotomy", 72, 45)
{
	_target = target;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj._target + "_Robotomy", 72, 45)
{
	*this = obj;
}


RobotomyRequestForm::~RobotomyRequestForm( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this == &obj)
		return (*this);
	_target = obj._target;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	this->Robotomy();
}

void	RobotomyRequestForm::Robotomy() const
{
	std::cout << "Drilling noises." << std::endl;
	std::srand((unsigned)time(0));
	if (std::rand() % 2 == 1)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	~RobotomyRequestForm( void );

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

	void	execute(Bureaucrat const & executor) const;

	void	Robotomy() const;

private:

	std::string	_target;
};

#endif

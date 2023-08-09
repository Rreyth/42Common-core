#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern(const Intern &obj);
	~Intern( void );

	Intern	&operator=(const Intern &obj);

	AForm	*makeForm(std::string name, std::string target);

	AForm	*createRobot(std::string target);
	AForm	*createShrubbery(std::string target);
	AForm	*createPardon(std::string target);

private:

};

#endif

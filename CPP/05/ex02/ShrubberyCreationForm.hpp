#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);

	void	execute(Bureaucrat const & executor) const;

	void	plant_tree() const;

private:

	std::string	_target;
};

#endif

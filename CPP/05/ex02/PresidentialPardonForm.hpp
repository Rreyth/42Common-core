#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	~PresidentialPardonForm( void );

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

	void	execute(Bureaucrat const & executor) const;
	void	pardon() const;

private:
	std::string	_target;

};

#endif

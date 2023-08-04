#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat( void );

	Bureaucrat	&operator=(const Bureaucrat &obj);

	void		setGrade(int grade);
	int			getGrade() const;
	std::string	getName() const;

	void		incrementGrade();
	void		decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	int					grade;
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj);

#endif

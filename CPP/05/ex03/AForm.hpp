#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm( void );
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm(const AForm &obj);
	virtual ~AForm( void );

	AForm	&operator=(const AForm &obj);

	std::string	getName() const;
	bool		getSignedStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;

	void			beSigned(Bureaucrat &signer);

	virtual void	execute(Bureaucrat const & executor) const;

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

	class  NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_exec;
};

std::ostream & operator << (std::ostream &out, const AForm &obj);

#endif

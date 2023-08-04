#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
public:
	Form( void );
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form &obj);
	~Form( void );

	Form	&operator=(const Form &obj);

	std::string	getName() const;
	bool		getSignedStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;

	void		beSigned(Bureaucrat &signer);

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
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_exec;
};

std::ostream & operator << (std::ostream &out, const Form &obj);

#endif

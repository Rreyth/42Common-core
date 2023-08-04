#include "Form.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Form::Form( void ) : _name("Default"), grade_to_sign(150), grade_to_exec(150)
{
	is_signed = false;
}


Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), grade_to_sign(sign_grade), grade_to_exec(exec_grade)
{
	is_signed = false;
	if (grade_to_exec > 150 || grade_to_sign > 150)
		throw (Form::GradeTooLowException());
	if (grade_to_exec < 1 || grade_to_sign < 1)
		throw (Form::GradeTooHighException());
}


Form::Form(const Form &obj) : _name(obj._name), grade_to_sign(obj.grade_to_sign), grade_to_exec(obj.grade_to_exec)
{
	*this = obj;
}


Form::~Form( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getSignedStatus() const
{
	return (is_signed);
}

int			Form::getGradeToSign() const
{
	return (grade_to_sign);
}

int			Form::getGradeToExec() const
{
	return (grade_to_exec);
}


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Form	&Form::operator=(const Form &obj)
{
	if (this == &obj)
		return (*this);
	this->is_signed = obj.is_signed;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Form &obj)
{
	out << "Form: " << obj.getName() << std::endl
		<< "signed status: " << obj.getSignedStatus() << std::endl
		<< "grade to sign: " << obj.getGradeToSign() << std::endl
		<< "grade to execute: " << obj.getGradeToExec();
	return (out);
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void		Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > grade_to_sign)
		throw (Form::GradeTooLowException());
	is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form exception: grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form exception: grade too low");
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

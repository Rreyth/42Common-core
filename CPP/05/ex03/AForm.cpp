#include "AForm.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
AForm::AForm( void ) : _name("Default"), grade_to_sign(150), grade_to_exec(150)
{
	is_signed = false;
}


AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), grade_to_sign(sign_grade), grade_to_exec(exec_grade)
{
	is_signed = false;
	if (grade_to_exec > 150 || grade_to_sign > 150)
		throw (AForm::GradeTooLowException());
	if (grade_to_exec < 1 || grade_to_sign < 1)
		throw (AForm::GradeTooHighException());
}


AForm::AForm(const AForm &obj) : _name(obj._name), grade_to_sign(obj.grade_to_sign), grade_to_exec(obj.grade_to_exec)
{
	*this = obj;
}


AForm::~AForm( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

std::string	AForm::getName() const
{
	return (_name);
}

bool		AForm::getSignedStatus() const
{
	return (is_signed);
}

int			AForm::getGradeToSign() const
{
	return (grade_to_sign);
}

int			AForm::getGradeToExec() const
{
	return (grade_to_exec);
}


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
AForm	&AForm::operator=(const AForm &obj)
{
	if (this == &obj)
		return (*this);
	this->is_signed = obj.is_signed;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const AForm &obj)
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

void		AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > grade_to_sign)
		throw (AForm::GradeTooLowException());
	is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!is_signed)
		throw (AForm::NotSignedException());
	if (executor.getGrade() > grade_to_exec)
		throw (AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form exception: grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form exception: grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form exception: form not signed");
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

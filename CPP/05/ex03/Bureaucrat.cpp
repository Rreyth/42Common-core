#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Bureaucrat::Bureaucrat( void ) : _name("Default")
{
	grade = 150;
}


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->grade = 150;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name)
{
	*this = obj;
}


Bureaucrat::~Bureaucrat( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

void		Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade = grade;
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this == &obj)
		return (*this);
	grade = obj.grade;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out);
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void		Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, max grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low, lowest grade is 150");
}

void		Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed form " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't sign form " << form.getName() << " because: "<< e.what() << std::endl;
	}
	
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << _name << " executed " << form.getName() << std::endl;
	}
	catch(AForm::NotSignedException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

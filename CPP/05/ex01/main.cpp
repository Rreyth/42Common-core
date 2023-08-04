#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat Billy("Billy", 1);
	Bureaucrat Philippe("Philippe", 150);
	Bureaucrat Billycpy(Billy);

	std::cout << "Billy: " << Billy << std::endl << "Billycpy: " << Billycpy << std::endl << "Philippe: " << Philippe << std::endl << std::endl;

	try
	{
		Form form("test", 151, 12);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form form("test", 150, 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form	form("get_formed", 15, 36);

	std::cout << std::endl << form << std::endl << std::endl;

	std::cout << Philippe << " try to sign form" << std::endl;
	Philippe.signForm(form);
	std::cout << form << std::endl << std::endl;

	std::cout << Billy << " try to sign form" << std::endl;
	Billy.signForm(form);
	std::cout << form << std::endl;

	return (0);
}
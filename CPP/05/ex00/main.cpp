#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat Billy("Billy", 1);
			Bureaucrat Philippe("Philippe", 151);
			Bureaucrat Billycpy(Billy);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat Billy("Billy", 0);
			Bureaucrat Philippe("Philippe", 150);
			Bureaucrat Billycpy(Billy);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Billy("Billy", 1);
		Bureaucrat Philippe("Philippe", 150);
		Bureaucrat Billycpy(Billy);

		std::cout << "Billy: " << Billy << std::endl << "Billycpy: " << Billycpy << std::endl << "Philippe: " << Philippe << std::endl << std::endl;

		try
		{
			std::cout << "increment Billy" << std::endl;
			Billy.incrementGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << Billy << std::endl << std::endl;
		
		try
		{
			std::cout << "decrement Billy" << std::endl;
			Billy.decrementGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Billy: " << Billy << std::endl << "Billycpy: " << Billycpy << std::endl << std::endl;

		try
		{
			std::cout << "decrement Philippe" << std::endl;
			Philippe.decrementGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << Philippe << std::endl << std::endl;

		Philippe.setGrade(36);
		std::cout << "set Philippe grade to 36" << std::endl << Philippe << std::endl << std::endl;

		try
		{
			std::cout << "set Philippe grade to 269" << std::endl;
			Philippe.setGrade(269);
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << Philippe << std::endl << std::endl;

		std::cout << "decrement Philippe" << std::endl;
		Philippe.decrementGrade();
		std::cout << Philippe << std::endl << std::endl;

		std::cout << "increment Philippe" << std::endl;
		Philippe.incrementGrade();
		std::cout << Philippe << std::endl << std::endl;
	}
	return (0);
}
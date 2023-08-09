#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

Base	*genA()
{
	return (new A);
}

Base	*genB()
{
	return (new B);
}

Base	*genC()
{
	return (new C);
}

Base	*generate()
{
	const struct {
		Base *(*ptr)();
	} generator[3] = {
		{&genA},
		{&genB},
		{&genC}
	};

	return (generator[std::rand() % 3].ptr());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "ptr: A";
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr: B";
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr: C";
	else
		std::cout << "ptr: Base";
}

void	identify(Base& p)
{
	try
	{
		Base &test = dynamic_cast<A&>(p);
		(void) test;
		std::cout << "ref: A";
	}
	catch (std::exception &e)
	{
		try
		{
			Base &test = dynamic_cast<B&>(p);
			(void) test;
			std::cout << "ref: B";
		}
		catch (std::exception &e)
		{
			try
			{
				Base &test = dynamic_cast<C&>(p);
				(void) test;
				std::cout << "ref: C";
			}
			catch (std::exception &e)
			{
				std::cout << "ref: Base";
			}
		}
	}
}

int	main()
{
	std::srand((unsigned)time(0));
	std::cout << "test with Base:" << std::endl;
	Base	*base = new Base;
	std::cout << "object type: ";
	identify(base);
	std::cout << " ";
	identify(*base);
	delete base;
	std::cout << std::endl << std::endl << "test with generate loop:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base	*base = generate();	
		std::cout << "object type: ";
		identify(base);
		std::cout << " ";
		identify(*base);
		std::cout << std::endl; 
		delete base;
	} 
	return (0);
}
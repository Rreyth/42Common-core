#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int	main()
{
	{
		std::cout << "subject tests:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "own tests" << std::endl;
		std::srand((unsigned)time(0));
		unsigned int loop = 10000;
		Span sp(loop);
		std::cout << "span of " << loop << " random numbers:" << std::endl;
		for (unsigned int i = 0; i < loop; i++)
		{
			sp.addNumber(std::rand());
		}
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		try
		{
			std::cout << std::endl << "try to add one over the max size:" << std::endl;
			sp.addNumber(5);
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp(8);
		std::cout << "try shortest and longuest on empty span:" << std::endl;
		try
		{
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		sp.addNumber(1);
		std::cout << "try shortest and longuest on span with only 1 element:" << std::endl;
		try
		{
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "test addNumbers" << std::endl;
		Span sp = Span(9);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(66);
		sp.addNumber(66);
		sp.addNumber(66);
		sp.addNumber(66);

		std::cout << "initial span: " << sp << std::endl;
		Span sp2(5);
		try
		{
			sp2.addNumbers(sp.getVectorBegin(), sp.getVectorEnd());			
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}		
		std::cout << "span made with addNumbers: " << sp2 << std::endl;
	}
	return (0);
}
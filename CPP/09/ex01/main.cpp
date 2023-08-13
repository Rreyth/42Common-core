#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./RPN \"1 2 + ...\"" << std::endl;
		return (1);
	}
	try
	{
		RPN	stack;
		stack.parseInput(av[1]);
		stack.calculator(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

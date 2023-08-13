#include <iostream>
#include <cstdlib>
#include <limits>
#include "PmergeMe.hpp"

bool validArgs(char **av)
{
	double test;
	for (int i = 1; av[i]; i++)
	{
		if (!*av[i])
			return (false);
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (false);
		}
		test = std::atof(av[i]);
		if (test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::min())
			return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac <= 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./PmergeMe <args>" << std::endl;
		return (1);
	}
	if (!validArgs(av))
	{
		std::cout << "Error: invalid arguments." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe test(av);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

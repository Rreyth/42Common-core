#include <iostream>
#include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./btc <infile>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange data;
		
		data.processInput(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

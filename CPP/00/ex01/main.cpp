#include "PhoneBook.hpp"


int	main(void)
{
	std::string line;
	PhoneBook book;

	std::getline(std::cin, line);
	while (line != "EXIT")
	{
		if (line == "ADD")
			book.add();
		if (line == "SEARCH")
			book.search();
		std::getline(std::cin, line);
	}
	return (0);
}

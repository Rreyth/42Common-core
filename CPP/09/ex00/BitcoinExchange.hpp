#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <stdexcept>

class BitcoinExchange
{
public:
	BitcoinExchange( void );
	BitcoinExchange(const BitcoinExchange &obj);
	~BitcoinExchange( void );

	BitcoinExchange	&operator=(const BitcoinExchange &obj);

	std::map<std::string, double>::iterator getBegin();
	std::map<std::string, double>::iterator getEnd();

	void	fillData();

	void	processInput(char *name);
	void	ComputeLine(std::string line, int i);

	class OpenDataException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  OpenInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  DataFormatException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	std::map<std::string, double> data;

};

#endif

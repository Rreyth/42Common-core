#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
BitcoinExchange::BitcoinExchange( void )
{
	fillData();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}


BitcoinExchange::~BitcoinExchange( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

std::map<std::string, double>::iterator BitcoinExchange::getBegin()
{
	return (data.begin());
}

std::map<std::string, double>::iterator BitcoinExchange::getEnd()
{
	return (data.end());
}

////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return (*this);
	data = obj.data;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

double	getValue(std::string line)
{
	return (std::atof(line.c_str()));
}

bool	validDate(std::string date)
{
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 7).c_str());
	int	day = std::atoi(date.substr(8, 10).c_str());

	if (month <= 0 || month > 12 || day <= 0 || day > 31 || year < 0)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (!(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month == 2 && day > 28)
		return (false);
	if (month == 2 && day > 29)
		return (false);
	return (true);
}

bool	isPositiveDouble(std::string line)
{
	int dot = 0;
	for (int i = 0; line[i]; i++)
	{
		if ((line[i] < 48 || line[i] > 57) && line[i] != '.')
			return (false);
		if (line[i] == '.' && dot >= 1)
			return (false);
		if (line[i] == '.')
			dot++;
	}
	if (line[line.size() - 1] == '.')
		return (false);
	double value = std::atof(line.c_str());
	if (value < 0)
		return (false);
	return (true);
}

bool	data_format(std::string line)
{
	if (line.empty())
		return (false);
	if (line[4] != '-' || line[7] != '-' || line[10] != ',')
		return (false);
	size_t dot = line.find(".");
	if (dot != std::string::npos && dot < 10)
		return (false);
	if (!validDate(line.substr(0, 10)))
		return (false);
	if (!isPositiveDouble(line.substr(11)))
		return (false);
	return (true);
}

void	BitcoinExchange::fillData()
{
	std::ifstream	file("data.csv", std::ifstream::in);

	if (!file.is_open())
		throw (BitcoinExchange::OpenDataException());

	std::string	line;

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw(BitcoinExchange::DataFormatException());
	std::getline(file, line);
	while (file)
	{
		if (!data_format(line))
			break ;
		data[line.substr(0, 10)] = getValue(line.substr(11));
		std::getline(file, line);
	}
	if (file)
	{
		file.close();
		throw (BitcoinExchange::DataFormatException());
	}
	file.close();
}

bool	tooManyBtc(std::string n)
{
	if (std::atof(n.c_str()) > 1000)
		return (true);
	return (false);
}

bool	inputFormat(std::string line, int i)
{
	if (line.empty())
	{
		std::cout << "Error: line " << i << " is empty" << std::endl;
		return (false);
	}
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
	{
		std::cout << "Error: Bad input format on line " << i << ": " << line << std::endl;
		return (false);
	}
	size_t dot = line.find(".");
	if (!validDate(line.substr(0, 10)) || (dot != std::string::npos && dot < 12))
	{
		std::cout << "Error: invalid date on line " << i << ": " << line.substr(0, 10) << std::endl;
		return (false);
	}
	if (!isPositiveDouble(line.substr(13)) || tooManyBtc(line.substr(13)))
	{
		std::cout << "Error: invalid number on line " << i << ": " << line.substr(13) << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::ComputeLine(std::string line, int i)
{
	std::string date = line.substr(0, 10);
	double value = getValue(line.substr(13));

	std::map<std::string, double>::iterator begin = data.begin();
	if (date < begin->first)
	{
		std::cout << "Error: invalid date on line " << i << ": " << date << " is before the start of data" << std::endl;
		return ;
	}

	std::map<std::string, double>::iterator end = data.end();
	std::map<std::string, double>::iterator res = begin;

	while (begin != end)
	{
		if (begin->first >= date)
			break ;
		res = begin;
		begin++;
	}
	if (begin->first == date)
		res = begin;
	std::cout.precision(9);
	std::cout << line << " = " << value * res->second << std::endl;
}

void	BitcoinExchange::processInput(char *name)
{
	std::ifstream	infile(name, std::ifstream::in);

	if(!infile.is_open())
		throw(BitcoinExchange::OpenInputException());

	std::string line;

	std::getline(infile, line);
	int i = 1;
	if (line == "date | value")
	{
		i++;
		std::getline(infile, line);
	}
	while (infile)
	{
		if (inputFormat(line, i))
			ComputeLine(line, i);
		std::getline(infile, line);
		i++;
	}
	infile.close();
}

const char* BitcoinExchange::OpenDataException::what() const throw()
{
	return ("Error: cannot open data.csv.");
}

const char* BitcoinExchange::OpenInputException::what() const throw()
{
	return ("Error: cannot open input file.");
}

const char* BitcoinExchange::DataFormatException::what() const throw()
{
	return ("Error: wrong data format.");
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

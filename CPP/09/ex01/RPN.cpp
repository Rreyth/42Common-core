#include "RPN.hpp"
#include <cstdlib>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
RPN::RPN( void )
{

}


RPN::RPN(const RPN &obj)
{
	*this = obj;
}


RPN::~RPN( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
RPN	&RPN::operator=(const RPN &obj)
{
	if (this == &obj)
		return (*this);
	stack = obj.stack;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	RPN::parseInput(std::string input)
{
	int nbSpace = 0;

	if (input.empty())
		throw (RPN::InputFormatException());
	for (int i = 0; input[i]; i++)
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '+'
			&& input[i] != '-' && input[i] != '*' && input[i] != '/'
			&& input[i] != ' ')
			throw (RPN::InputFormatException());
		if (input[i] == ' ')
			nbSpace++;
		else
			nbSpace = 0;
		if (nbSpace > 1)
			throw (RPN::InputFormatException());
	}
}

void	RPN::calculator(std::string input)
{
	for (int i = 0; input[i]; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			stack.push(std::atoi(input.substr(i, i + 1).c_str()));
		if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			if (stack.size() < 2)
				throw (RPN::ComputeException());
			compute(input[i]);
		}
	}
	if (stack.size() > 1)
		throw (RPN::NotEmptyException());
	std::cout << stack.top() << std::endl;
}

void	RPN::compute(char sign)
{
	int n1 = stack.top();
	stack.pop();
	int n2 = stack.top();
	stack.pop();

	if (sign == '+')
		stack.push(n2 + n1);
	if (sign == '-')
		stack.push(n2 - n1);
	if (sign == '*')
		stack.push(n2 * n1);
	if (sign == '/')
		stack.push(n2 / n1);
}

const char* RPN::InputFormatException::what() const throw()
{
	return ("Error: invalid input format.");
}

const char* RPN::NotEmptyException::what() const throw()
{
	return ("Error: too many numbers or not enough signs.");
}

const char* RPN::ComputeException::what() const throw()
{
	return ("Error: calculation on less than 2 numbers.");
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

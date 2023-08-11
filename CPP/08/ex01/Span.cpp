#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Span::Span( void )
{
	maxSize = 0;
	sorted = false;
}


Span::Span(unsigned int N)
{
	maxSize = N;
	sorted = false;
}


Span::Span(const Span &obj)
{
	*this = obj;
}


Span::~Span( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

int		Span::getVectorValue(int n) const
{
	return (vector[n]);
}

int		Span::getVectorSize() const
{
	return (vector.size());
}

std::vector<int>::iterator	Span::getVectorBegin()
{
	return (vector.begin());
}

std::vector<int>::iterator	Span::getVectorEnd()
{
	return (vector.end());
}


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Span	&Span::operator=(const Span &obj)
{
	if (this == &obj)
		return (*this);
	maxSize = obj.maxSize;
	vector = obj.vector;
	sorted = obj.sorted;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Span &obj)
{
	out << "{";
	for (int i = 0; i < obj.getVectorSize(); i++)
	{
		if (i != 0)
			out << ", ";
		out << obj.getVectorValue(i);
	}
	out << "}";
	return (out);
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	Span::addNumber(int n)
{
	if (vector.size() < maxSize)
	{
		vector.push_back(n);
		sorted = false;
	}
	else
		throw(Span::FullSpanException());
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (int i = 0; begin != end; i++)
	{
		addNumber(*begin);
		begin++;
	}
}

int	Span::shortestSpan()
{
	if (vector.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	if (!sorted)
	{
		std::sort(vector.begin(), vector.end());
		sorted = true;
	}
	int	shortest = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < maxSize; i++)
	{
		if (vector[i] - vector[i - 1] < shortest)
			shortest = vector[i] - vector[i - 1];
	}
	return (shortest);
}

int	Span::longestSpan()
{
	if (vector.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	if (!sorted)
	{
		std::sort(vector.begin(), vector.end());
		sorted = true;
	}
	return (vector.back() - vector.front());
}

const char* Span::FullSpanException::what() const throw()
{
	return ("Span is already full.");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough in numbers Span.");
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

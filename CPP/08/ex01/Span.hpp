#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
public:
	Span( void );
	Span(unsigned int N);
	Span(const Span &obj);
	~Span( void );

	Span	&operator=(const Span &obj);

	void	addNumber(int);

	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int		shortestSpan();
	int		longestSpan();

	int		getVectorValue(int) const;
	int		getVectorSize() const;

	std::vector<int>::iterator	getVectorBegin();
	std::vector<int>::iterator	getVectorEnd();

	class FullSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	std::vector<int>	vector;
	unsigned int		maxSize;
	bool				sorted;
};

std::ostream & operator << (std::ostream &out, const Span &obj);

#endif

#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>

class Span
{
public:
	Span( void );
	Span(unsigned int N);
	Span(const Span &obj);
	~Span( void );

	Span	&operator=(const Span &obj);

	void	addNumber(int);

	int		shortestSpan();
	int		longestSpan();

private:
	std::list<int>	list;
	unsigned int	maxSize;
};

#endif

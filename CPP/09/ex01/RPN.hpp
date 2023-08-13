#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN
{
public:
	RPN( void );
	RPN(const RPN &obj);
	~RPN( void );

	RPN	&operator=(const RPN &obj);

	void	parseInput(std::string);
	void	calculator(std::string);
	void	compute(char);

	class  InputFormatException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  NotEmptyException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class  ComputeException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	std::stack<int>	stack;
};

#endif

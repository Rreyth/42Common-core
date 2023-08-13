#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

typedef struct s_Pair
{
	int				value;
	struct s_Pair	*p1;
	struct s_Pair	*p2;
}		t_Pair;

class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe(char **av);
	PmergeMe(const PmergeMe &obj);
	~PmergeMe( void );

	PmergeMe	&operator=(const PmergeMe &obj);

	void	vectorSort(char **av);
	void	listSort(char **av);

private:
	std::vector<int>	vector;
	std::list<int>		list;
};

std::ostream & operator << (std::ostream &out, const std::vector<int> &obj);
std::ostream & operator << (std::ostream &out, std::list<int> &obj);

#endif

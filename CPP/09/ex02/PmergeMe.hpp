#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

typedef struct s_Pair
{
	int	v1;
	int	v2;
}		t_Pair;

class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe(char **av);
	PmergeMe(const PmergeMe &obj);
	~PmergeMe( void );

	PmergeMe	&operator=(const PmergeMe &obj);

	double	vectorSort();
	double	dequeSort();

	void	fillVectorPairs(t_Pair *pairs, int nb_pairs);
	void	fillDequePairs(t_Pair *pairs, int nb_pairs);
	void	vectorMinsInsert(t_Pair *pairs, int nb_pairs, std::vector<int> &res);
	void	dequeMinsInsert(t_Pair *pairs, int nb_pairs, std::deque<int> &res);

	void	printValues();

	int		getVectorSize();
	int		getDequeSize();
	int		vectorPairs();
	int		dequePairs();


private:
	std::vector<int>	vector;
	std::deque<int>		deque;
};

std::ostream & operator << (std::ostream &out, const std::vector<int> &obj);
std::ostream & operator << (std::ostream &out, const std::deque<int> &obj);

#endif

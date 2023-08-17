#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
PmergeMe::PmergeMe( void )
{

}


PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		vector.push_back(std::atoi(av[i]));
		deque.push_back(std::atoi(av[i]));
	}
}


PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}


PmergeMe::~PmergeMe( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

int		PmergeMe::getVectorSize()
{
	return (vector.size());
}

int		PmergeMe::getDequeSize()
{
	return (deque.size());
}

int		PmergeMe::vectorPairs()
{
	int 			count = 0;
	unsigned long	i = 0;

	while (i < vector.size())
	{
		if (i % 2 != 0)
			count++;
		i++;
	}
	return (count);
}

int		PmergeMe::dequePairs()
{
	int 			count = 0;
	unsigned long	i = 0;

	while (i < deque.size())
	{
		if (i % 2 != 0)
			count++;
		i++;
	}
	return (count);
}

////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	vector = obj.vector;
	deque = obj.deque;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const std::vector<int> &obj)
{
	out << "{";
	for (unsigned long i = 0; i < obj.size(); i++)
	{
		if (i != 0)
			out << ", ";
		out << obj[i];
	}
	out << "}";
	return (out);
}

std::ostream & operator << (std::ostream &out, const std::deque<int> &obj)
{
	out << "{";
	for (unsigned long i = 0; i < obj.size(); i++)
	{
		if (i != 0)
			out << ", ";
		out << obj[i];
	}
	out << "}";
	return (out);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	PmergeMe::fillVectorPairs(t_Pair *pairs, int nb_pairs)
{
	unsigned long i = 0;
	for (int j = 0; j < nb_pairs; j++)
	{
		pairs[j].v1 = vector[i];
		pairs[j].v2 = vector[i + 1];
		i += 2;
	}

	int tmp;

	for (int j = 0; j < nb_pairs; j++)
	{
		if (pairs[j].v1 > pairs[j].v2 && pairs[j].v2 >= 0)
		{
			tmp = pairs[j].v1;
			pairs[j].v1 = pairs[j].v2;
			pairs[j].v2 = tmp;
		}
	}
}

void	PmergeMe::fillDequePairs(t_Pair *pairs, int nb_pairs)
{
	unsigned long i = 0;
	for (int j = 0; j < nb_pairs; j++)
	{
		pairs[j].v1 = deque[i];
		pairs[j].v2 = deque[i + 1];
		i += 2;
	}

	int tmp;

	for (int j = 0; j < nb_pairs; j++)
	{
		if (pairs[j].v1 > pairs[j].v2 && pairs[j].v2 >= 0)
		{
			tmp = pairs[j].v1;
			pairs[j].v1 = pairs[j].v2;
			pairs[j].v2 = tmp;
		}
	}
}

void	recursiveSortVector(t_Pair *pairs, int idx, std::vector<int> &res)
{
	if (idx != 0)
		recursiveSortVector(pairs, idx - 1, res);
	if (res.size() == 0)
	{
		res.push_back(pairs[idx].v2);
		return ;
	}

	std::vector<int>::iterator begin = res.begin();
	std::vector<int>::iterator end = res.end();

	while (begin != end)
	{
		if (pairs[idx].v2 < *begin)
		{
			res.insert(begin, pairs[idx].v2);
			break ;
		}
		begin++;
	}
	if (begin == end)
		res.push_back(pairs[idx].v2);
}

void	recursiveSortDeque(t_Pair *pairs, int idx, std::deque<int> &res)
{
	if (idx != 0)
		recursiveSortDeque(pairs, idx - 1, res);
	if (res.size() == 0)
	{
		res.push_back(pairs[idx].v2);
		return ;
	}

	std::deque<int>::iterator begin = res.begin();
	std::deque<int>::iterator end = res.end();

	while (begin != end)
	{
		if (pairs[idx].v2 < *begin)
		{
			res.insert(begin, pairs[idx].v2);
			break ;
		}
		begin++;
	}
	if (begin == end)
		res.push_back(pairs[idx].v2);
}

size_t	maxVectorIndex(std::vector<int> res, int value)
{
	size_t max = 0;

	while (max < res.size())
	{
		if (res[max] == value)
			break ;
		max++;
	}
	return (max);
}

size_t	maxDequeIndex(std::deque<int> res, int value)
{
	size_t max = 0;

	while (max < res.size())
	{
		if (res[max] == value)
			break ;
		max++;
	}
	return (max);
}

std::vector<int>::iterator vectorBinarySearch(std::vector<int> &res, size_t max, int value)
{
	std::vector<int>::iterator	pos = res.begin();
	for (size_t i = 0; i < max; i++)
	{
		if (value < res[i])
			break ;
		pos++;
	}
	return (pos);
}

std::deque<int>::iterator dequeBinarySearch(std::deque<int> &res, size_t max, int value)
{
	std::deque<int>::iterator	pos = res.begin();
	for (size_t i = 0; i < max; i++)
	{
		if (value < res[i])
			break ;
		pos++;
	}
	return (pos);
}

void	invertValues(t_Pair* pairs, int size, int nb_pairs)
{
	t_Pair	tmp[size];

	if (size > nb_pairs)
		size = nb_pairs;
	for (int i = 0; i < size; i++)
	{
		tmp[i] = pairs[size - 1 - i];
	}

	for (int i = 0; i < size; i++)
	{
		pairs[i] = tmp[i];
	}
}

void	PairsSort(t_Pair *pairs, int nb_pairs)
{
	int nb0 = 2;
	int nb1 = 2;
	for (int i = 0; i < nb_pairs;)
	{
		invertValues(&pairs[i], nb0, nb_pairs - i);
		i += nb0;
		if (i < nb_pairs)
		{
			invertValues(&pairs[i], nb1, nb_pairs - i);
			i += nb1;
		}
		nb0 = nb0 * 2 + nb1;
		nb1 = nb1 * 2 + nb0;
	} 
}

void	PmergeMe::vectorMinsInsert(t_Pair *pairs, int nb_pairs, std::vector<int> &res)
{
	std::vector<int>::iterator begin = res.begin();

	for (int i = 0; i < nb_pairs; i++)
	{
		if (pairs[i].v2 == res[0])
		{
			res.insert(begin, pairs[i].v1);
			pairs[i].v1 = -1;
			break;
		}
	}

	PairsSort(pairs, nb_pairs);

	std::vector<int>::iterator pos;
	size_t	max;

	for (int i = 0; i < nb_pairs; i++)
	{
		if (pairs[i].v1 != -1)
		{
			max = maxVectorIndex(res, pairs[i].v2);
			pos = vectorBinarySearch(res, max, pairs[i].v1);
			res.insert(pos, pairs[i].v1);
		}
	}

	if (vector.size() % 2 != 0)
	{
		pos = vectorBinarySearch(res, res.size(), vector.back());
		res.insert(pos, vector.back());
	}
}

void	PmergeMe::dequeMinsInsert(t_Pair *pairs, int nb_pairs, std::deque<int> &res)
{
	std::deque<int>::iterator begin = res.begin();

	for (int i = 0; i < nb_pairs; i++)
	{
		if (pairs[i].v2 == res[0])
		{
			res.insert(begin, pairs[i].v1);
			pairs[i].v1 = -1;
			break;
		}
	}

	PairsSort(pairs, nb_pairs);

	std::deque<int>::iterator pos;
	size_t	max;

	for (int i = 0; i < nb_pairs; i++)
	{
		if (pairs[i].v1 != -1)
		{
			max = maxDequeIndex(res, pairs[i].v2);
			pos = dequeBinarySearch(res, max, pairs[i].v1);
			res.insert(pos, pairs[i].v1);
		}
	}

	if (deque.size() % 2 != 0)
	{
		pos = dequeBinarySearch(res, res.size(), deque.back());
		res.insert(pos, deque.back());
	}
}

double	PmergeMe::vectorSort()
{
	double time = clock()/(double)(CLOCKS_PER_SEC);
	int nb_pairs = vectorPairs();
	t_Pair pairs[nb_pairs];
	fillVectorPairs(pairs, nb_pairs);

	std::vector<int>	res;
	recursiveSortVector(pairs, nb_pairs - 1, res);

	vectorMinsInsert(pairs, nb_pairs, res);

	vector = res;

	time = ((clock()/(double)(CLOCKS_PER_SEC)) - time) * 1000000;
	return (time);
}

double	PmergeMe::dequeSort()
{
	double time = clock()/(double)(CLOCKS_PER_SEC);
	int nb_pairs = dequePairs();
	t_Pair pairs[nb_pairs];
	fillDequePairs(pairs, nb_pairs);

	std::deque<int>	res;
	recursiveSortDeque(pairs, nb_pairs - 1, res);

	dequeMinsInsert(pairs, nb_pairs, res);

	deque = res;

	time = ((clock()/(double)(CLOCKS_PER_SEC)) - time) * 1000000;
	return (time);
}

void	PmergeMe::printValues()
{
	std::cout << vector << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

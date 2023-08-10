#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <class T>
int	easyfind(T container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
		throw (std::invalid_argument("parameter not inside container"));
	
	int	res = 0;

	while (it != container.begin())
	{
		res++;
		it--;
	}
	return (res);
}

#endif
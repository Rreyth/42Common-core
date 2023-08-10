#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void	swap(T &first, T &second)
{
	T tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T	min(const T first, const T second)
{
	if (first < second)
		return (first);
	return (second);
}

template <typename T>
T	max(const T first, const T second)
{
	if (first > second)
		return (first);
	return (second);
}

#endif
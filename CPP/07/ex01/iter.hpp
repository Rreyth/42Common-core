#ifndef ITER_HPP
# define ITER_HPP

template <typename A, typename L, typename P>
void	iter(A *array, L length, P fct)
{
	for (L i = 0; i < length; i++)
	{
		fct(array[i]);
	}
}

template <typename T>
void	printfct(T a)
{
	std::cout << a << std::endl;
}


#endif
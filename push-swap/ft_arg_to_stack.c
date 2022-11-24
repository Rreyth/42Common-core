/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:26:38 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 23:09:35 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	size_src;
	int	size_dst;

	i = 0;
	j = 0;
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	while (dst[i] != '\0' && i < size)
		i++;
	size_dst = i;
	if (dst[i] == '\0')
	{
		while (src[j] != '\0' && i < size)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (size_dst + size_src);
}
*/

char	*ft_join_args(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 1;
	k = 0;
	j = ft_args_len(ac, av) + ac;
	str = ft_calloc(j, sizeof(char));
	if (!str)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] == '+'))
			{
				str[k] = av[i][j];
				k++;
			}
			j++;
		}
		str[k] = 32;
		k++;
		i++;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		if (result * negative > 2147483647)
			return (-1);
		if (result * negative < -2147483648)
			return (0);
		i++;
	}
	return (result * negative);
}

int	*ft_atoi_tab(char **tab)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc((sizeof(int *)) * (ft_tab_len(tab)));
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (res);
}

int	*ft_get_stacked(int ac, char **av)
{
	char	*joined;
	char	**splited;
	int		*stacked;
//	int		i;

	joined = ft_join_args(ac, av);
//	if (!joined)
//		ft_exit_error();
	splited = ft_split(joined, ' ');
//	if (!splited)
	free(joined);
	stacked = ft_atoi_tab(splited);
//	if (!stacked)
/*	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);*/
	return (stacked);
}

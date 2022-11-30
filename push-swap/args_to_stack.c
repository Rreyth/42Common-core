/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:26:38 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/30 12:07:19 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strcat_args(char *str, char **av, int ac)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			str[k] = av[i][j];
			k++;
			j++;
		}
		str[k] = 32;
		k++;
		i++;
	}
}

char	*ft_join_args(int ac, char **av)
{
	int		j;
	char	*str;

	j = ft_args_len(ac, av) + ac;
	str = ft_calloc(j, sizeof(char));
	if (!str)
		ft_exit_error();
	ft_strcat_args(str, av, ac);
	return (str);
}

int	ft_atoi(const char *nptr, t_struct **stack, char **tab)
{
	int			i;
	long long	result;
	int			negative;

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
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		ft_atoi_error(stack, tab);
	if (result * negative > 2147483647 || result * negative < -2147483648)
		ft_atoi_error(stack, tab);
	return (result * negative);
}

void	ft_atoi_tab(char **tab, t_struct **stack)
{
	int	i;

	if (!*tab)
		ft_exit_error();
	i = 0;
	(*stack)->tab = malloc((sizeof(int)) * (ft_tab_len(tab)));
	if (!((*stack)->tab))
		ft_atoi_error(stack, tab);
	while (tab[i])
	{
		(*stack)->tab[i] = ft_atoi((tab)[i], stack, tab);
		i++;
	}
	(*stack)->max_size = i;
	(*stack)->size = i;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

t_struct	*args_to_stack(int ac, char **av)
{
	int			i;
	char		*args_join;
	char		**args_split;
	t_struct	*stack;

	i = 0;
	args_split = NULL;
	stack = malloc(sizeof(t_struct));
	if (!stack)
		ft_exit_error();
	args_join = ft_join_args(ac, av);
	args_split = ft_split(args_join, ' ');
	free(args_join);
	if (!args_split)
		ft_exit_error();
	ft_atoi_tab(args_split, &stack);
	ft_check_duplicate(&stack);
	return (stack);
}

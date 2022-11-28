/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:39:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/28 17:11:31 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_args_len(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		i++;
	}
	return (len);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_is_sort(t_struct *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	normalize(t_struct *stack)
{
	int	*tmp;
	int	norm;
	int	i;
	int	j;

	i = 0;
	tmp = malloc(sizeof(int) * stack->size);
	if (!tmp)
		ft_free_error(&stack);
	while (i < stack->size)
	{
		j = 0;
		norm = 0;
		while (j < stack->size)
			if (stack->tab[i] > stack->tab[j++])
				norm++;
		tmp[i] = norm;
		i++;
	}
	i = -1;
	while (++i < stack->size)
		stack->tab[i] = tmp[i];
	free(tmp);
}

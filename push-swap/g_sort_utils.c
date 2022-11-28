/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:35:45 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/28 21:42:14 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(t_struct *stack)
{
	int	highest;
	int	i;

	highest = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->tab[highest] < stack->tab[i])
			highest = i;
		i++;
	}
	return (highest);
}

int	find_s_highest(t_struct *stack, int highest)
{
	int	s_highest;
	int	i;

	i = 0;
	s_highest = 0;
	while (i < stack->size)
	{
		if ((stack->tab[highest] - 1) == stack->tab[i])
			s_highest = i;
		i++;
	}
	return (s_highest);
}

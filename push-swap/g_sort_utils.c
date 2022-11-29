/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:35:45 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/29 14:17:07 by tdhaussy         ###   ########.fr       */
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

int	find_pivot(t_struct *stack)
{
	int	pvt;
	int	div;

	div = (stack->size / 10) + 15;
	div = stack->size / div;
	if (div == 0)
		div = 3;
	pvt = stack->size / div;
	return (pvt);
}

int	check_closest(t_struct *stack, int f_index, int s_index)
{
	int	f_range;
	int	s_range;

	if (f_index > (stack->size / 2))
		f_range = stack->size - f_index + 1;
	else
		f_range = f_index;
	if (s_index > (stack->size / 2))
		s_range = stack->size - s_index + 1;
	else
		s_range = s_index;
	if (f_range < s_range)
		return (1);
	else
		return (2);
}

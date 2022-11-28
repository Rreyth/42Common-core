/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:40:06 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/28 22:45:13 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_push(t_struct *stack_a, t_struct *stack_b, int div)
{
	int	i;
	int	pvt;
	int	mid;

	pvt = stack_a->max_size / div;
	mid = pvt / 2;
	while (pvt <= stack_a->max_size)
	{
		i = 0;
		while (i < stack_a->max_size / div)
		{
			if (stack_a->tab[0] < pvt)
			{
				push(stack_a, stack_b, 'b');
				i++;
				if (stack_b->tab[0] > (pvt - mid) && stack_b->size != 1)
					rotate(stack_b, 'b');
			}
			else
				rotate(stack_a, 'a');
		}
		pvt += stack_a->max_size / div;
	}
}

int	check_closest(t_struct *stack, int f_index, int s_index)
{
	int	f_range;
	int	s_range;

	if (f_index > (stack->size / 2))
		f_range = stack->size - f_index;
	else
		f_range = f_index;
	if (s_index > (stack->size / 2))
		s_range = stack->size - s_index;
	else
		s_range = s_index;
	if (f_range < s_range)
		return (1);
	else
		return (2);
}

void	smart_rotate(t_struct *stack, int target_index, char name)
{
	if (target_index >= (stack->size / 2) && stack->size > 1)
	{
		while (target_index < stack->size)
		{
			reverse_rotate(stack, name);
			target_index++;
		}
	}
	else if (target_index < (stack->size / 2) && stack->size > 1)
	{
		while (target_index > 0)
		{
			rotate(stack, name);
			target_index--;
		}
	}
}

void	push_back(t_struct *stack_a, t_struct *stack_b)
{
	int	highest;
	int	s_highest;
	int	closest;

	while (stack_b->size != 0)
	{
		highest = find_highest(stack_b);
		s_highest = find_s_highest(stack_b, highest);
		closest = check_closest(stack_b, highest, s_highest);
		if (closest == 1)
		{
			smart_rotate(stack_b, highest, 'b');
			push(stack_a, stack_b, 'a');
			s_highest = find_highest(stack_b);
			smart_rotate(stack_b, s_highest, 'b');
			push(stack_a, stack_b, 'a');
		}
		else
		{
			smart_rotate(stack_b, s_highest, 'b');
			push(stack_a, stack_b, 'a');
			highest = find_highest(stack_b);
			smart_rotate(stack_b, highest, 'b');
			push(stack_a, stack_b, 'a');
			if (!ft_is_sort(stack_a))
				swap(stack_a, 'a');
		}
	}
}

void	global_sort(t_struct *stack_a)
{
	t_struct	*stack_b;
	int			div;

	div = 3;
	if (stack_a->max_size >= 200)
		div = 8;
	stack_b = malloc(sizeof(t_struct));
	if (!stack_b)
		ft_free_error(&stack_a);
	stack_b->tab = ft_calloc(stack_a->max_size, sizeof(int));
	if (!stack_b->tab)
	{
		ft_free_stack(&stack_b);
		ft_free_error(&stack_a);
	}
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	part_push(stack_a, stack_b, div);
	push_back(stack_a, stack_b);
	ft_free_stack(&stack_b);
}

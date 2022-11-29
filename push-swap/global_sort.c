/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:40:06 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/29 14:25:30 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_push(t_struct *stack_a, t_struct *stack_b)
{
	int	i;
	int	pvt;
	int	mid;
	int	init_pvt;

	init_pvt = find_pivot(stack_a);
	pvt = init_pvt;
	mid = pvt / 2;
	while (stack_a->size > 0)
	{
		i = 0;
		while (i < init_pvt)
		{
			if (stack_a->tab[0] < pvt)
			{
				push(stack_a, stack_b, 'b');
				i++;
				if (stack_b->tab[0] > (pvt - mid) && stack_b->size > 1)
					rotate(stack_b, 'b');
			}
			else
				rotate(stack_a, 'a');
		}
		pvt += init_pvt;
	}
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

void	smart_push(int first, int second, t_struct *stack_a, t_struct *stack_b)
{
	smart_rotate(stack_b, first, 'b');
	push(stack_a, stack_b, 'a');
	second = find_highest(stack_b);
	smart_rotate(stack_b, second, 'b');
	push(stack_a, stack_b, 'a');
	if (!ft_is_sort(stack_a))
		swap(stack_a, 'a');
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
			smart_push(highest, s_highest, stack_a, stack_b);
		else
			smart_push(s_highest, highest, stack_a, stack_b);
	}
}

void	global_sort(t_struct *stack_a)
{
	t_struct	*stack_b;

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
	part_push(stack_a, stack_b);
	push_back(stack_a, stack_b);
	ft_free_stack(&stack_b);
}

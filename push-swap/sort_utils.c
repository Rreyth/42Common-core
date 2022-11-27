/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:00:56 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/27 19:06:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct *stack, char name)
{
	int	tmp;

	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
}

void	dual_swap(t_struct *stack_a, t_struct *stack_b)
{
	swap(stack_a, ' ');
	swap(stack_b, ' ');
	write(1, "ss\n", 3);
}

void	push(t_struct *stack_a, t_struct *stack_b, char name)
{
	if (name == 'a')
	{
		if (!stack_b || stack_b->size == 0)
			return ;
		stack_a->size += 1;
		reverse_rotate(stack_a, ' ');
		stack_a->tab[0] = stack_b->tab[0];
		stack_b->tab[0] = 0;
		rotate(stack_b, ' ');
		stack_b->size -= 1;
		write(1, "pa\n", 3);
	}
	else if (name == 'b')
	{
		if (!stack_a || stack_a->size == 0)
			return ;
		stack_b->size += 1;
		reverse_rotate(stack_b, ' ');
		stack_b->tab[0] = stack_a->tab[0];
		stack_a->tab[0] = 0;
		rotate(stack_a, ' ');
		stack_a->size -= 1;
		write(1, "pb\n", 3);
	}
}

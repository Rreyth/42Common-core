/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:39:42 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/30 18:44:22 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_swap(t_struct *stack)
{
	int	tmp;

	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
}

void	checker_dual_swap(t_struct *stack_a, t_struct *stack_b)
{
	checker_swap(stack_a);
	checker_swap(stack_b);
}

void	checker_push(t_struct *stack_a, t_struct *stack_b, char name)
{
	if (name == 'a')
	{
		if (!stack_b || stack_b->size == 0)
			return ;
		stack_a->size += 1;
		checker_reverse_rotate(stack_a);
		stack_a->tab[0] = stack_b->tab[0];
		stack_b->tab[0] = 0;
		checker_rotate(stack_b);
		stack_b->size -= 1;
	}
	else if (name == 'b')
	{
		if (!stack_a || stack_a->size == 0)
			return ;
		stack_b->size += 1;
		checker_reverse_rotate(stack_b);
		stack_b->tab[0] = stack_a->tab[0];
		stack_a->tab[0] = 0;
		checker_rotate(stack_a);
		stack_a->size -= 1;
	}
}

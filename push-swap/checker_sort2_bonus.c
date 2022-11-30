/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:43:33 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/30 19:16:56 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_rotate(t_struct *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->tab[0];
	while (i + 1 < stack->size)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
}

void	checker_dual_rotate(t_struct *stack_a, t_struct *stack_b)
{
	checker_rotate(stack_a);
	checker_rotate(stack_b);
}

void	checker_reverse_rotate(t_struct *stack)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
}

void	checker_dual_reverse_rotate(t_struct *stack_a, t_struct *stack_b)
{
	checker_reverse_rotate(stack_a);
	checker_reverse_rotate(stack_b);
}

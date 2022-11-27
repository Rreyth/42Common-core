/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:07:32 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/27 22:20:47 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_struct *stack, char name)
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
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
}

void	dual_rotate(t_struct *stack_a, t_struct *stack_b)
{
	rotate(stack_a, ' ');
	rotate(stack_b, ' ');
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_struct *stack, char name)
{
	int	tmp;
	int	i;

	i = stack->size;
	tmp = stack->tab[i - 1];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
}

void	dual_reverse_rotate(t_struct *stack_a, t_struct *stack_b)
{
	reverse_rotate(stack_a, ' ');
	reverse_rotate(stack_b, ' ');
	write(1, "rrr\n", 4);
}

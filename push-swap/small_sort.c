/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:33:42 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/28 21:21:48 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_struct *stack)
{
	if (ft_is_sort(stack))
		return ;
	if ((stack->tab[0] > stack->tab[1] && stack->tab[1] > stack->tab[2])
		|| (stack->tab[0] < stack->tab[1] && stack->tab[0] < stack->tab[2])
		|| (stack->tab[0] > stack->tab[1] && stack->tab[0] < stack->tab[2]))
		swap(stack, 'a');
	if (stack->tab[0] > stack->tab[1] && stack->tab[0] > stack->tab[2])
		rotate(stack, 'a');
	if (stack->tab[0] < stack->tab[1] && stack->tab[0] > stack->tab[2])
		reverse_rotate(stack, 'a');
}

void	up_smallest(t_struct *stack, int index, char name)
{
	if (index == 1)
		swap(stack, name);
	else if (index == 2)
	{
		rotate(stack, name);
		swap(stack, name);
	}
	else if (index == stack->size - 1)
		reverse_rotate(stack, name);
	else if (index == 3)
	{	
		reverse_rotate(stack, name);
		reverse_rotate(stack, name);
	}
}

void	push_smallest(t_struct *stack_a, t_struct *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack_a->size)
	{
		if (stack_a->tab[i] > stack_a->tab[j])
			i = j;
		j++;
	}
	up_smallest(stack_a, i, 'a');
	if (!ft_is_sort(stack_a))
		push(stack_a, stack_b, 'b');
}

void	sort_45(t_struct *stack_a)
{
	t_struct	*stack_b;

	stack_b = malloc(sizeof(t_struct));
	if (!stack_b)
		ft_free_error(&stack_a);
	stack_b->tab = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_b->tab)
	{
		ft_free_stack(&stack_b);
		ft_free_error(&stack_a);
	}
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	push_smallest(stack_a, stack_b);
	if (stack_a->max_size == 5 && !(ft_is_sort(stack_a)))
		push_smallest(stack_a, stack_b);
	sort_3(stack_a);
	push(stack_a, stack_b, 'a');
	if (stack_a->max_size == 5)
		push(stack_a, stack_b, 'a');
	ft_free_stack(&stack_b);
}

void	small_sort(t_struct *stack)
{
	if (stack->size == 3)
		sort_3(stack);
	if (stack->size == 4 || stack->size == 5)
		sort_45(stack);
}

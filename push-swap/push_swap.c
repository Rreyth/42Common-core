/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:26:18 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/30 16:08:41 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_launch_sort(t_struct *stack_a)
{
	if (stack_a->max_size == 2)
		swap(stack_a, 'a');
	else if (stack_a->max_size >= 3 && stack_a->max_size <= 5)
		small_sort(stack_a);
	else
		global_sort(stack_a);
}

int	main(int argc, char **argv)
{
	t_struct	*stack_a;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = args_to_stack(argc, argv);
	normalize(stack_a);
	if (!(ft_is_sort(stack_a)))
		ft_launch_sort(stack_a);
	ft_free_stack(&stack_a);
	return (0);
}

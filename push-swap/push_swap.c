/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:26:18 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 23:09:56 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	stack_a;
	int			i;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = ft_get_stacked(argc, argv);
	while (i < stack_a.size)
	{
		printf("%d", stack_a.tab[i]);
		i++;
	}
	ft_free_stack(stack_a);
	return (0);
}

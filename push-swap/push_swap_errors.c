/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:23:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/27 17:07:10 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_check_char(char c, int op)
{
	if (op > 1 || (!(c >= '0' && c <= '9')
			&& (c != '+' && c != '-' && c != ' ')) || (op == 1 && c == 32))
		ft_exit_error();
	if (c == '+' || c == '-')
		op++;
	else
		op = 0;
	return (op);
}

void	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;
	int	op;
	int	count;

	i = 1;
	op = 0;
	while (i < ac)
	{
		count = 0;
		j = 0;
		while (av[i][j])
		{
			op = ft_check_char(av[i][j], op);
			if (av[i][j] >= '0' && av[i][j] <= '9')
				count++;
			j++;
		}
		if (op > 0)
			ft_exit_error();
		if (count < 1)
			ft_exit_error();
		i++;
	}
}

void	ft_check_duplicate(t_struct **stack)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < (*stack)->size)
	{
		j = i + 1;
		while (j < (*stack)->size)
		{
			if ((*stack)->tab[i] == (*stack)->tab[j])
				ft_free_error(stack);
			j++;
		}
		i++;
	}
}

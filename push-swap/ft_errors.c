/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:23:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 22:00:01 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

//void	ft_free_error()

void	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;
	int	op;
	int	count;

	i = 1;
	op = 0;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
				op++;
			else
				op = 0;
			if (op > 1 || (!(av[i][j] >= '0' && av[i][j] <= '9')
					&& (av[i][j] != '+' && av[i][j] != '-' && av[i][j] != ' ')))
				ft_exit_error();
			if (av[i][j] >= '0' && av[i][j] <= '9')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		ft_exit_error();
}

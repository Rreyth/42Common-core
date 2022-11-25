/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:51:12 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/25 22:52:38 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_struct **s)
{
	free((*s)->tab);
	free(*s);
}

void	ft_free_error(t_struct **s)
{
	free((*s)->tab);
	free(*s);
	ft_exit_error();
}

void	ft_atoi_error(t_struct **s, char **tab)
{
	int	i;

	i = 0;
	if (*s)
	{
		if ((*s)->tab)
			free((*s)->tab);
		free(*s);
	}
	(void) tab;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
	ft_exit_error();
}

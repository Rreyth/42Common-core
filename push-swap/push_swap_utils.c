/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:39:26 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 23:09:15 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_args_len(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		i++;
	}
	return (len);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free_stack(t_struct s)
{
	int	i;
	free(s.tab);
	free(s);
}

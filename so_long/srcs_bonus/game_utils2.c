/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:17:55 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/18 23:31:29 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_enemy(char c)
{
	if (c == 'X' || c == '9' || c == '8' || c == '7')
		return (1);
	return (0);
}

void	find_enemy(t_vars *vars)
{
	int	i;
	int	j;
	int	down;

	i = 1;
	while (vars->map[i])
	{
		j = 1;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'X' || vars->map[i][j] == '9'
					|| vars->map[i][j] == '8' || vars->map[i][j] == '7')
			{
				if (vars->map[i][j + 1] == '0' && j != down)
				{
					enemy_move(vars, i, j, &down);
					j++;
				}
				else if (j != down)
					enemy_move(vars, i, j, &down);
			}
			j++;
		}
		i++;
	}
}

char	*make_screen_count(int count)
{
	char	*str;
	char	*str_count;

	str_count = ft_itoa(count);
	str = ft_strjoin("moves = ", str_count);
	free(str_count);
	return (str);
}

void	end_pos(t_vars *vars, int *x, int *y)
{
	int	len;
	int	nb_line;

	len = ft_strlen(vars->map[0]);
	nb_line = count_line(vars->map);
	if (len <= 10)
	{
		if (len % 2 == 0)
			*x = ((len / 2) * 64) - (192 / 2);
		else
			*x = ((len / 2) * 64) - 64;
		*y = ((nb_line * 64) / 2) - 64;
	}
	else
	{
		if (len % 2 == 0)
			*x = ((len / 2) * 64) - 192;
		else
			*x = ((len / 2) * 64) - 160;
		if (nb_line % 2 == 0)
			*y = ((nb_line * 64) / 2) - (192 / 2);
		else
			*y = ((nb_line * 64) / 2) - 64;
	}
}

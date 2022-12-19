/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:31:03 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/18 21:43:15 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	e_move_up(t_vars *vars, int x, int y)
{
	if (vars->map[x - 1][y] == '0')
	{
		vars->map[x - 1][y] = '8';
		vars->map[x][y] = '0';
	}
	if (vars->map[x - 1][y] == 'P' || vars->map[x - 1][y] == 'U'
		|| vars->map[x - 1][y] == 'D' || vars->map[x - 1][y] == 'L')
	{
		vars->map[x - 1][y] = '8';
		vars->map[x][y] = '0';
		end_game(vars, x - 1, y, 0);
	}
}

void	e_move_down(t_vars *vars, int x, int y)
{
	if (vars->map[x + 1][y] == '0')
	{
		vars->map[x + 1][y] = '7';
		vars->map[x][y] = '0';
	}
	if (vars->map[x + 1][y] == 'P' || vars->map[x + 1][y] == 'U'
		|| vars->map[x + 1][y] == 'D' || vars->map[x + 1][y] == 'L')
	{
		vars->map[x + 1][y] = '7';
		vars->map[x][y] = '0';
		end_game(vars, x + 1, y, 0);
	}
}

void	e_move_left(t_vars *vars, int x, int y)
{
	if (vars->map[x][y - 1] == '0')
	{
		vars->map[x][y - 1] = 'X';
		vars->map[x][y] = '0';
	}
	if (vars->map[x][y - 1] == 'P' || vars->map[x][y - 1] == 'U'
		|| vars->map[x][y - 1] == 'D' || vars->map[x][y - 1] == 'L')
	{
		vars->map[x][y - 1] = 'X';
		vars->map[x][y] = '0';
		end_game(vars, x, y - 1, 0);
	}
}

void	e_move_right(t_vars *vars, int x, int y)
{
	if (vars->map[x][y + 1] == '0')
	{
		vars->map[x][y + 1] = '9';
		vars->map[x][y] = '0';
	}
	if (vars->map[x][y + 1] == 'P' || vars->map[x][y + 1] == 'U'
		|| vars->map[x][y + 1] == 'D' || vars->map[x][y + 1] == 'L')
	{
		vars->map[x][y + 1] = '9';
		vars->map[x][y] = '0';
		end_game(vars, x, y + 1, 0);
	}
}

void	enemy_move(t_vars *vars, int i, int j, int *down)
{
	int	diff_x;
	int	diff_y;

	diff_x = vars->x - i;
	diff_y = vars->y - j;
	vars->enemy_timer = 4;
	*down = 0;
	if (diff_x < 0 && ((diff_y <= 0 && diff_x < diff_y)
			|| (diff_y >= 0 && diff_y < -diff_x)))
		e_move_up(vars, i, j);
	else if (diff_x > 0 && ((diff_y <= 0 && diff_y > -diff_x)
			|| (diff_y >= 0 && diff_y < diff_x)))
	{
		e_move_down(vars, i, j);
		*down = j;
	}
	else if (diff_y < 0)
		e_move_left(vars, i, j);
	else if (diff_y > 0)
		e_move_right(vars, i, j);
}

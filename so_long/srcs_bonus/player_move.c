/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:23:03 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 01:09:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	end_game(t_vars *vars, int x, int y, int move)
{
	if (move)
	{
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
	if (is_enemy(vars->map[x][y]))
		vars->end = 2;
	else
		vars->end = 1;
}

void	p_move_up(t_vars *vars)
{
	if (vars->map[vars->x - 1][vars->y] == 'E'
			|| is_enemy(vars->map[vars->x - 1][vars->y]))
	{
		move_exit_enemy(vars, vars->x - 1, vars->y, '3');
		vars->x -= 1;
	}
	else if (vars->map[vars->x - 1][vars->y] != '1')
	{
		vars->map[vars->x - 1][vars->y] = 'U';
		if (vars->map[vars->x][vars->y] == '2'
				|| vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->x -= 1;
		vars->move_count++;
		vars->enemy_timer--;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

void	p_move_down(t_vars *vars)
{
	if (vars->map[vars->x + 1][vars->y] == 'E'
			|| is_enemy(vars->map[vars->x + 1][vars->y]))
	{
		move_exit_enemy(vars, vars->x + 1, vars->y, '2');
		vars->x += 1;
	}
	else if (vars->map[vars->x + 1][vars->y] != '1')
	{
		vars->map[vars->x + 1][vars->y] = 'P';
		if (vars->map[vars->x][vars->y] == '2'
				|| vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->x += 1;
		vars->move_count++;
		vars->enemy_timer--;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

void	p_move_left(t_vars *vars)
{
	if (vars->map[vars->x][vars->y - 1] == 'E'
			|| is_enemy(vars->map[vars->x][vars->y - 1]))
	{
		move_exit_enemy(vars, vars->x, vars->y - 1, '5');
		vars->y -= 1;
	}
	else if (vars->map[vars->x][vars->y - 1] != '1')
	{
		vars->map[vars->x][vars->y - 1] = 'L';
		if (vars->map[vars->x][vars->y] == '2'
				|| vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->y -= 1;
		vars->move_count++;
		vars->enemy_timer--;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

void	p_move_right(t_vars *vars)
{
	if (vars->map[vars->x][vars->y + 1] == 'E'
			|| is_enemy(vars->map[vars->x][vars->y + 1]))
	{
		move_exit_enemy(vars, vars->x, vars->y + 1, '2');
		vars->y += 1;
	}
	else if (vars->map[vars->x][vars->y + 1] != '1')
	{
		vars->map[vars->x][vars->y + 1] = 'P';
		if (vars->map[vars->x][vars->y] == '2'
				|| vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->y += 1;
		vars->move_count++;
		vars->enemy_timer--;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

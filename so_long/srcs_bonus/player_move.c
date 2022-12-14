/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:23:03 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/14 19:32:54 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	end_game(t_vars *vars)
{
	vars->move_count++;
	ft_printf("number of movements : %d\n", vars->move_count);
	close_win(vars);
}

void	p_move_up(t_vars *vars)
{
	if (vars->map[vars->x - 1][vars->y] == 'E' && has_collectible(vars->map))
	{
		vars->map[vars->x - 1][vars->y] = '3';
		vars->map[vars->x][vars->y] = '0';
		vars->x -= 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
	else if ((vars->map[vars->x - 1][vars->y] == 'E'
		&& !has_collectible(vars->map))
		|| vars->map[vars->x - 1][vars->y] == 'X')
		end_game(vars);
	else if (vars->map[vars->x - 1][vars->y] != '1')
	{
		vars->map[vars->x - 1][vars->y] = 'U';
		if (vars->map[vars->x][vars->y] == '2' || vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '4' || vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->x -= 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}	
}

void	p_move_down(t_vars *vars)
{
	if (vars->map[vars->x + 1][vars->y] == 'E' && has_collectible(vars->map))
	{
		vars->map[vars->x + 1][vars->y] = '4';
		vars->map[vars->x][vars->y] = '0';
		vars->x += 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
	else if ((vars->map[vars->x + 1][vars->y] == 'E'
		&& !has_collectible(vars->map))
		|| vars->map[vars->x + 1][vars->y] == 'X')
		end_game(vars);
	else if (vars->map[vars->x + 1][vars->y] != '1')
	{
		vars->map[vars->x + 1][vars->y] = 'D';
		if (vars->map[vars->x][vars->y] == '2' || vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '4' || vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->x += 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

void	p_move_left(t_vars *vars)
{
	if (vars->map[vars->x][vars->y - 1] == 'E' && has_collectible(vars->map))
	{
		vars->map[vars->x][vars->y - 1] = '5';
		vars->map[vars->x][vars->y] = '0';
		vars->y -= 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
	else if ((vars->map[vars->x][vars->y - 1] == 'E'
		&& !has_collectible(vars->map))
		|| vars->map[vars->x][vars->y - 1] == 'X')
		end_game(vars);
	else if (vars->map[vars->x][vars->y - 1] != '1')
	{
		vars->map[vars->x][vars->y - 1] = 'L';
		if (vars->map[vars->x][vars->y] == '2' || vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '4' || vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->y -= 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

void	p_move_right(t_vars *vars)
{
	if (vars->map[vars->x][vars->y + 1] == 'E' && has_collectible(vars->map))
	{
		vars->map[vars->x][vars->y + 1] = '2';
		vars->map[vars->x][vars->y] = '0';
		vars->y += 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
	else if ((vars->map[vars->x][vars->y + 1] == 'E'
		&& !has_collectible(vars->map))
		|| vars->map[vars->x][vars->y + 1] == 'X')
		end_game(vars);
	else if (vars->map[vars->x][vars->y + 1] != '1')
	{
		vars->map[vars->x][vars->y + 1] = 'P';
		if (vars->map[vars->x][vars->y] == '2' || vars->map[vars->x][vars->y] == '3'
				|| vars->map[vars->x][vars->y] == '4' || vars->map[vars->x][vars->y] == '5')
			vars->map[vars->x][vars->y] = 'E';
		else
			vars->map[vars->x][vars->y] = '0';
		vars->y += 1;
		display_map(vars);
		vars->move_count++;
		ft_printf("number of movements : %d\n", vars->move_count);
	}
}

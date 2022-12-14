/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:45:52 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/14 19:43:01 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_player(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player, (j * 64), (i * 64));
	else if (vars->map[i][j] == '2')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_up, (j * 64), (i * 64));
	else if (vars->map[i][j] == '3')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_up_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'D')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_down, (j * 64), (i * 64));
	else if (vars->map[i][j] == '4')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_down_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_left, (j * 64), (i * 64));
	else if (vars->map[i][j] == '5')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_left_exit, (j * 64), (i * 64));
}

void	display_enemy(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy, (j * 64), (i * 64));
}

void	display_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P' || vars->map[i][j] == '2'
		|| vars->map[i][j] == 'U' || vars->map[i][j] == '3'
		|| vars->map[i][j] == 'D' || vars->map[i][j] == '4'
		|| vars->map[i][j] == 'L' || vars->map[i][j] == '5')
		display_player(vars, i, j);
	if (vars->map[i][j] == 'X')
		display_enemy(vars, i, j);
	else if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, (j * 64), (i * 64));
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ground, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->coin, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E' && !has_collectible(vars->map))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->o_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, (j * 64), (i * 64));
}

void	display_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			display_img(vars, i, j);
			j++;
		}
		i++;
	}
}

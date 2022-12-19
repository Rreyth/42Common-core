/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:24:20 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 20:25:30 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_anim(t_vars *vars)
{
	if (vars->p_idle == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p_afk,
			(vars->y * 64), (vars->x * 64));
		vars->p_idle++;
	}
	else if (vars->p_idle == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p_afk1,
			(vars->y * 64), (vars->x * 64));
		vars->p_idle++;
	}
	else if (vars->p_idle == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p_afk2,
			(vars->y * 64), (vars->x * 64));
		vars->p_idle = 0;
	}
}

void	enemy_anim(t_vars *vars, int x, int y)
{
	if (vars->x_idle == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->x_afk,
			(y * 64), (x * 64));
	else if (vars->x_idle == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->x_afk1,
			(y * 64), (x * 64));
	else if (vars->x_idle == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->x_afk2,
			(y * 64), (x * 64));
}

void	display_anim(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	if (vars->afk_time < 60000)
		return ;
	vars->afk_time -= 15000;
	player_anim(vars);
	while (vars->map[i])
	{
		j = 1;
		while (vars->map[i][j])
		{
			if (is_enemy(vars->map[i][j]))
				enemy_anim(vars, i, j);
			j++;
		}
		i++;
	}
	vars->x_idle++;
	if (vars->x_idle == 3)
		vars->x_idle = 0;
}

void	coin_anim(t_vars *vars, int x, int y)
{
	if (vars->c_anim < 15000)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coin,
			(y * 64), (x * 64));
	else if (vars->c_anim > 15000 && vars->c_anim < 30000)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_idle,
			(y * 64), (x * 64));
	else if (vars->c_anim > 30000 && vars->c_anim < 45000)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_idle1,
			(y * 64), (x * 64));
	else if (vars->c_anim > 45000)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_idle2,
			(y * 64), (x * 64));
	if (vars->c_anim > 60000)
		vars->c_anim = 0;
}

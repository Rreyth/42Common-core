/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:24:20 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 00:27:49 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_anim(t_vars *vars)
{
	if (vars->idle == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.p_afk,
			(vars->y * 64), (vars->x * 64));
	else if (vars->idle == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.p_afk1,
			(vars->y * 64), (vars->x * 64));
	else if (vars->idle == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.p_afk2,
			(vars->y * 64), (vars->x * 64));
}

void	enemy_anim(t_vars *vars, int x, int y)
{
	if (vars->idle == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.x_afk,
			(y * 64), (x * 64));
	else if (vars->idle == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.x_afk1,
			(y * 64), (x * 64));
	else if (vars->idle == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.x_afk2,
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
	vars->idle++;
	if (vars->idle == 3)
		vars->idle = 0;
}

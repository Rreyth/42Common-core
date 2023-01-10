/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:45:52 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 01:23:24 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.wall, (j * 64), (i * 64));
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.ground, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.player, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.coin, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E' && !has_collectible(vars->map))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.o_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == '2')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.p_exit, (j * 64), (i * 64));
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

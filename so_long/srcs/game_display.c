/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:45:52 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/13 22:59:41 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, (j * 64), (i * 64));
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ground, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->coin, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E' && !has_collectible(vars->map))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->o_exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, (j * 64), (i * 64));
	else if (vars->map[i][j] == '2')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->p_exit, (j * 64), (i * 64));
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

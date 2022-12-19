/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:45:52 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/18 22:59:20 by tdhaussy         ###   ########.fr       */
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
	if (vars->map[i][j] == '9')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy_right, (j * 64), (i * 64));
	if (vars->map[i][j] == '8')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy_up, (j * 64), (i * 64));
	if (vars->map[i][j] == '7')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy_down, (j * 64), (i * 64));
}

void	display_img(t_vars *vars, int i, int j)
{
	display_player(vars, i, j);
	display_enemy(vars, i, j);
	if (vars->map[i][j] == '1')
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
	int		i;
	int		j;
	char	*count;

	i = 0;
	while (vars->map[i] && vars->end == 0)
	{
		j = 0;
		while (vars->map[i][j])
		{
			display_img(vars, i, j);
			j++;
		}
		i++;
	}
	if (vars->end != 0)
	{
		display_img(vars, 0, 0);
		display_img(vars, 0, 1);
	}
	count = make_screen_count(vars->move_count);
	mlx_string_put(vars->mlx, vars->win, 20, 30, 0x00FFFF00, count);
	free(count);
}

void	display_end(t_vars *vars)
{
	int	x;
	int	y;

	end_pos(vars, &x, &y);
	if (vars->end == 1)
	{
		if (ft_strlen(vars->map[0]) <= 10)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->game_sw, x, y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->game_w, x, y);
	}
	if (vars->end == 2)
	{
		if (ft_strlen(vars->map[0]) <= 10)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->game_so, x, y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->game_o, x, y);
	}
}

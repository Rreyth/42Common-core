/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:38:25 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 01:22:40 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->sprite.coin);
	mlx_destroy_image(vars->mlx, vars->sprite.wall);
	mlx_destroy_image(vars->mlx, vars->sprite.player);
	mlx_destroy_image(vars->mlx, vars->sprite.ground);
	mlx_destroy_image(vars->mlx, vars->sprite.exit);
	mlx_destroy_image(vars->mlx, vars->sprite.p_exit);
	mlx_destroy_image(vars->mlx, vars->sprite.o_exit);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_map(vars->map);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_win(vars);
	if (keycode == XK_Up || keycode == XK_w)
		p_move_up(vars);
	if (keycode == XK_Down || keycode == XK_s)
		p_move_down(vars);
	if (keycode == XK_Left || keycode == XK_a)
		p_move_left(vars);
	if (keycode == XK_Right || keycode == XK_d)
		p_move_right(vars);
	return (0);
}

void	find_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->x = i;
				vars->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	game_init(t_vars *vars, char **map)
{
	int	width;
	int	height;

	width = ft_strlen(map[0]) * 64;
	height = count_line(map) * 64;
	vars->map = copy_map(map);
	ft_free_map(map);
	vars->move_count = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "so_long");
	vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx, W_PATH,
			&width, &height);
	vars->sprite.ground = mlx_xpm_file_to_image(vars->mlx, G_PATH,
			&width, &height);
	vars->sprite.player = mlx_xpm_file_to_image(vars->mlx, P_PATH,
			&width, &height);
	vars->sprite.coin = mlx_xpm_file_to_image(vars->mlx, C_PATH,
			&width, &height);
	vars->sprite.exit = mlx_xpm_file_to_image(vars->mlx, E_PATH,
			&width, &height);
	vars->sprite.p_exit = mlx_xpm_file_to_image(vars->mlx, PE_PATH,
			&width, &height);
	vars->sprite.o_exit = mlx_xpm_file_to_image(vars->mlx, OE_PATH,
			&width, &height);
	find_player(vars);
}

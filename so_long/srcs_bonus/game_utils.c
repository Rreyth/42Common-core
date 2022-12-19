/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:38:25 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 19:49:33 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	img_destroy(vars);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_map(vars->map);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_win(vars);
	if (vars->end == 0)
	{
		if (keycode == XK_Up || keycode == XK_w || keycode == XK_Down
			|| keycode == XK_s || keycode == XK_Left || keycode == XK_a
			|| keycode == XK_Right || keycode == XK_d)
			vars->afk_time = 0;
		if (keycode == XK_Up || keycode == XK_w)
			p_move_up(vars);
		if (keycode == XK_Down || keycode == XK_s)
			p_move_down(vars);
		if (keycode == XK_Left || keycode == XK_a)
			p_move_left(vars);
		if (keycode == XK_Right || keycode == XK_d)
			p_move_right(vars);
	}
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
	img_init(vars, width, height);
	vars->end = 0;
	find_player(vars);
	vars->enemy_timer = 4;
	vars->afk_time = 0;
	vars->p_idle = 0;
	vars->x_idle = 0;
	vars->c_anim = 0;
}

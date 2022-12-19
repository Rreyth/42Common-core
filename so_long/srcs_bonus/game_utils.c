/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:38:25 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 00:19:12 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->coin);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->ground);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->p_exit);
	mlx_destroy_image(vars->mlx, vars->o_exit);
	mlx_destroy_image(vars->mlx, vars->enemy);
	mlx_destroy_image(vars->mlx, vars->enemy_right);
	mlx_destroy_image(vars->mlx, vars->enemy_up);
	mlx_destroy_image(vars->mlx, vars->enemy_down);
	mlx_destroy_image(vars->mlx, vars->p_up);
	mlx_destroy_image(vars->mlx, vars->p_up_exit);
	mlx_destroy_image(vars->mlx, vars->p_down);
	mlx_destroy_image(vars->mlx, vars->p_down_exit);
	mlx_destroy_image(vars->mlx, vars->p_left);
	mlx_destroy_image(vars->mlx, vars->p_left_exit);
	mlx_destroy_image(vars->mlx, vars->game_sw);
	mlx_destroy_image(vars->mlx, vars->game_so);
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
		if (keycode == XK_Up || keycode == XK_w)
			p_move_up(vars);
		if (keycode == XK_Down || keycode == XK_s)
			p_move_down(vars);
		if (keycode == XK_Left || keycode == XK_a)
			p_move_left(vars);
		if (keycode == XK_Right || keycode == XK_d)
			p_move_right(vars);
	}
	display_map(vars);
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
	vars->wall = mlx_xpm_file_to_image(vars->mlx, W_PATH, &width, &height);
	vars->ground = mlx_xpm_file_to_image(vars->mlx, G_PATH, &width, &height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, P_PATH, &width, &height);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, C_PATH, &width, &height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, E_PATH, &width, &height);
	vars->p_exit = mlx_xpm_file_to_image(vars->mlx, PE_PATH, &width, &height);
	vars->o_exit = mlx_xpm_file_to_image(vars->mlx, OE_PATH, &width, &height);
	vars->enemy = mlx_xpm_file_to_image(vars->mlx, X_PATH, &width, &height);	
	vars->enemy_right = mlx_xpm_file_to_image(vars->mlx, XR_PATH, &width, &height);
	vars->enemy_up = mlx_xpm_file_to_image(vars->mlx, XU_PATH, &width, &height);
	vars->enemy_down = mlx_xpm_file_to_image(vars->mlx, XD_PATH, &width, &height);
	vars->p_up = mlx_xpm_file_to_image(vars->mlx, PU_PATH, &width, &height);
	vars->p_up_exit = mlx_xpm_file_to_image(vars->mlx, PUE_PATH, &width, &height);
	vars->p_down = mlx_xpm_file_to_image(vars->mlx, PD_PATH, &width, &height);
	vars->p_down_exit = mlx_xpm_file_to_image(vars->mlx, PDE_PATH, &width, &height);
	vars->p_left = mlx_xpm_file_to_image(vars->mlx, PL_PATH, &width, &height);
	vars->p_left_exit = mlx_xpm_file_to_image(vars->mlx, PLE_PATH, &width, &height);
	vars->game_sw = mlx_xpm_file_to_image(vars->mlx, S_WIN, &width, &height);
	vars->game_w = mlx_xpm_file_to_image(vars->mlx, WIN, &width, &height);
	vars->game_so = mlx_xpm_file_to_image(vars->mlx, S_OVER, &width, &height);
	vars->game_o = mlx_xpm_file_to_image(vars->mlx, OVER, &width, &height);
	vars->end = 0;
	find_player(vars);
	vars->enemy_timer = 4;
}

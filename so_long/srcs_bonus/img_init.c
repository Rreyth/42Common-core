/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:13:46 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 00:35:32 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	base_sprites(t_vars *vars, int w, int h)
{
	vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx, W_PATH, &w, &h);
	vars->sprite.ground = mlx_xpm_file_to_image(vars->mlx, G_PATH, &w, &h);
	vars->sprite.player = mlx_xpm_file_to_image(vars->mlx, P_PATH, &w, &h);
	vars->sprite.coin = mlx_xpm_file_to_image(vars->mlx, C_PATH, &w, &h);
	vars->sprite.exit = mlx_xpm_file_to_image(vars->mlx, E_PATH, &w, &h);
	vars->sprite.p_exit = mlx_xpm_file_to_image(vars->mlx, PE_PATH, &w, &h);
	vars->sprite.o_exit = mlx_xpm_file_to_image(vars->mlx, OE_PATH, &w, &h);
	vars->sprite.enemy = mlx_xpm_file_to_image(vars->mlx, X_PATH, &w, &h);
	vars->sprite.game_sw = mlx_xpm_file_to_image(vars->mlx, S_WIN, &w, &h);
	vars->sprite.game_w = mlx_xpm_file_to_image(vars->mlx, WIN, &w, &h);
	vars->sprite.game_so = mlx_xpm_file_to_image(vars->mlx, S_OVER, &w, &h);
	vars->sprite.game_o = mlx_xpm_file_to_image(vars->mlx, OVER, &w, &h);
}

void	direction_sprites(t_vars *vars, int w, int h)
{
	vars->sprite.enemy_right = mlx_xpm_file_to_image(vars->mlx, XR_PATH,
			&w, &h);
	vars->sprite.enemy_up = mlx_xpm_file_to_image(vars->mlx, XU_PATH, &w, &h);
	vars->sprite.p_up = mlx_xpm_file_to_image(vars->mlx, PU_PATH, &w, &h);
	vars->sprite.p_up_exit = mlx_xpm_file_to_image(vars->mlx, PUE_PATH, &w, &h);
	vars->sprite.p_left = mlx_xpm_file_to_image(vars->mlx, PL_PATH, &w, &h);
	vars->sprite.p_left_exit = mlx_xpm_file_to_image(vars->mlx, PLE_PATH,
			&w, &h);
}

void	anim_sprites(t_vars *vars, int w, int h)
{
	vars->sprite.p_afk = mlx_xpm_file_to_image(vars->mlx, P_AFK, &w, &h);
	vars->sprite.p_afk1 = mlx_xpm_file_to_image(vars->mlx, P_AFK1, &w, &h);
	vars->sprite.p_afk2 = mlx_xpm_file_to_image(vars->mlx, P_AFK2, &w, &h);
	vars->sprite.x_afk = mlx_xpm_file_to_image(vars->mlx, X_AFK, &w, &h);
	vars->sprite.x_afk1 = mlx_xpm_file_to_image(vars->mlx, X_AFK1, &w, &h);
	vars->sprite.x_afk2 = mlx_xpm_file_to_image(vars->mlx, X_AFK2, &w, &h);
}

void	img_init(t_vars *vars, int width, int height)
{
	base_sprites(vars, width, height);
	direction_sprites(vars, width, height);
	anim_sprites(vars, width, height);
}

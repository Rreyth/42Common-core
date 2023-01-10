/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:30:07 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 00:24:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	base_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.coin);
	mlx_destroy_image(vars->mlx, vars->sprite.wall);
	mlx_destroy_image(vars->mlx, vars->sprite.player);
	mlx_destroy_image(vars->mlx, vars->sprite.ground);
	mlx_destroy_image(vars->mlx, vars->sprite.exit);
	mlx_destroy_image(vars->mlx, vars->sprite.p_exit);
	mlx_destroy_image(vars->mlx, vars->sprite.o_exit);
	mlx_destroy_image(vars->mlx, vars->sprite.enemy);
	mlx_destroy_image(vars->mlx, vars->sprite.game_sw);
	mlx_destroy_image(vars->mlx, vars->sprite.game_w);
	mlx_destroy_image(vars->mlx, vars->sprite.game_so);
	mlx_destroy_image(vars->mlx, vars->sprite.game_o);
}

void	direction_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.enemy_right);
	mlx_destroy_image(vars->mlx, vars->sprite.enemy_up);
	mlx_destroy_image(vars->mlx, vars->sprite.p_up);
	mlx_destroy_image(vars->mlx, vars->sprite.p_up_exit);
	mlx_destroy_image(vars->mlx, vars->sprite.p_left);
	mlx_destroy_image(vars->mlx, vars->sprite.p_left_exit);
}

void	anim_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.p_afk);
	mlx_destroy_image(vars->mlx, vars->sprite.p_afk1);
	mlx_destroy_image(vars->mlx, vars->sprite.p_afk2);
	mlx_destroy_image(vars->mlx, vars->sprite.x_afk);
	mlx_destroy_image(vars->mlx, vars->sprite.x_afk1);
	mlx_destroy_image(vars->mlx, vars->sprite.x_afk2);
}

void	img_destroy(t_vars *vars)
{
	base_destroy(vars);
	direction_destroy(vars);
	anim_destroy(vars);
}

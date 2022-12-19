/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:30:07 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 19:57:38 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	base_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->coin);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->ground);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->p_exit);
	mlx_destroy_image(vars->mlx, vars->o_exit);
	mlx_destroy_image(vars->mlx, vars->enemy);
	mlx_destroy_image(vars->mlx, vars->game_sw);
	mlx_destroy_image(vars->mlx, vars->game_w);
	mlx_destroy_image(vars->mlx, vars->game_so);
	mlx_destroy_image(vars->mlx, vars->game_o);
}

void	direction_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->enemy_right);
	mlx_destroy_image(vars->mlx, vars->enemy_up);
	mlx_destroy_image(vars->mlx, vars->enemy_down);
	mlx_destroy_image(vars->mlx, vars->p_up);
	mlx_destroy_image(vars->mlx, vars->p_up_exit);
	mlx_destroy_image(vars->mlx, vars->p_down);
	mlx_destroy_image(vars->mlx, vars->p_down_exit);
	mlx_destroy_image(vars->mlx, vars->p_left);
	mlx_destroy_image(vars->mlx, vars->p_left_exit);
}

void	anim_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->p_afk);
	mlx_destroy_image(vars->mlx, vars->p_afk1);
	mlx_destroy_image(vars->mlx, vars->p_afk2);
	mlx_destroy_image(vars->mlx, vars->x_afk);
	mlx_destroy_image(vars->mlx, vars->x_afk1);
	mlx_destroy_image(vars->mlx, vars->x_afk2);
	mlx_destroy_image(vars->mlx, vars->c_idle);
	mlx_destroy_image(vars->mlx, vars->c_idle1);
	mlx_destroy_image(vars->mlx, vars->c_idle2);
}

void	img_destroy(t_vars *vars)
{
	base_destroy(vars);
	direction_destroy(vars);
	anim_destroy(vars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:19:05 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 00:20:15 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	loop_fct(t_vars *vars)
{
	if (vars->enemy_timer == 0 && vars->end == 0)
		find_enemy(vars);
//	display_anim(vars);
	display_end(vars);
	return (0);
}

void	game_launch(char **map)
{
	t_vars	vars;
	int		i;

	i = 1;
	game_init(&vars, map);
	display_map(&vars);
	mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
	mlx_hook(vars.win, 17, (1L << 17), close_win, &vars);
	mlx_loop_hook(vars.mlx, loop_fct, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	char	**map;

	check_args(argc, argv[1]);
	map = make_map(argv[1]);
	game_launch(map);
	return (0);
}

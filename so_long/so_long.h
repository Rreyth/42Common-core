/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/10 01:20:39 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define W_PATH "textures/wall.xpm"
# define G_PATH "textures/ground.xpm"
# define P_PATH "textures/player.xpm"
# define C_PATH "textures/coin.xpm"
# define E_PATH "textures/exit.xpm"
# define PE_PATH "textures/player_exit.xpm"
# define OE_PATH "textures/open_exit.xpm"

typedef struct s_sprite {
	void	*coin;
	void	*wall;
	void	*player;
	void	*ground;
	void	*exit;
	void	*o_exit;
	void	*p_exit;
}				t_sprite;

typedef struct s_vars {
	t_sprite	sprite;
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
	int			move_count;
}				t_vars;

/*---------------------------------Parsing------------------------------------*/
void	check_args(int ac, char *file);
void	check_map(char **map);
void	parse_error(int code);
void	ft_free_map(char **map);
void	map_error(char **map);
void	fill_map(char **map, int x, int y);
char	**make_map(char *file);
char	*so_long_join(char *s1, char *s2);
char	**copy_map(char **map);
int		has_collectible(char **map);
int		has_player(char **map);
int		has_exit(char **map);
int		is_filled(char **map);

/*---------------------------------GAME---------------------------------------*/
void	game_init(t_vars *vars, char **map);
void	display_map(t_vars *vars);
void	p_move_up(t_vars *vars);
void	p_move_down(t_vars *vars);
void	p_move_left(t_vars *vars);
void	p_move_right(t_vars *vars);
int		close_win(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

#endif 

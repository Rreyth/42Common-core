/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/19 20:36:08 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define PU_PATH "textures/player_up.xpm"
# define PUE_PATH "textures/player_up_exit.xpm"
# define PD_PATH "textures/player_down.xpm"
# define PDE_PATH "textures/player_down_exit.xpm"
# define PL_PATH "textures/player_left.xpm"
# define PLE_PATH "textures/player_left_exit.xpm"
# define OE_PATH "textures/open_exit.xpm"
# define X_PATH "textures/enemy.xpm"
# define XU_PATH "textures/enemy_up.xpm"
# define XD_PATH "textures/enemy_down.xpm"
# define XR_PATH "textures/enemy_right.xpm"
# define S_WIN "textures/small_win_screen.xpm"
# define WIN "textures/win_screen.xpm"
# define S_OVER "textures/small_game_over.xpm"
# define OVER "textures/game_over.xpm"
# define P_AFK "textures/player_afk.xpm"
# define P_AFK1 "textures/player_afk1.xpm"
# define P_AFK2 "textures/player_afk2.xpm"
# define X_AFK "textures/enemy_afk.xpm"
# define X_AFK1 "textures/enemy_afk1.xpm"
# define X_AFK2 "textures/enemy_afk2.xpm"
# define C_IDLE "textures/player_afk.xpm"
# define C_IDLE1 "textures/player_afk1.xpm"
# define C_IDLE2 "textures/player_afk2.xpm"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	void	*coin;
	void	*wall;
	void	*player;
	void	*ground;
	void	*exit;
	void	*o_exit;
	void	*p_exit;
	void	*p_up;
	void	*p_up_exit;
	void	*p_down;
	void	*p_down_exit;
	void	*p_left;
	void	*p_left_exit;
	void	*enemy;
	void	*enemy_right;
	void	*enemy_up;
	void	*enemy_down;
	void	*game_sw;
	void	*game_w;
	void	*game_so;
	void	*game_o;
	void	*p_afk;
	void	*p_afk1;
	void	*p_afk2;
	void	*x_afk;
	void	*x_afk1;
	void	*x_afk2;
	void	*c_idle;
	void	*c_idle1;
	void	*c_idle2;
	int		x;
	int		y;
	int		move_count;
	int		enemy_timer;
	int		end;
	int		afk_time;
	int		p_idle;
	int		x_idle;
	int		c_anim;
}				t_vars;

/*---------------------------------Parsing------------------------------------*/
void	check_args(int ac, char *file);
char	**make_map(char *file);
void	check_map(char **map);
void	parse_error(int code);
void	ft_free_map(char **map);
void	map_error(char **map);
char	*so_long_join(char *s1, char *s2);
int		has_collectible(char **map);
int		has_player(char **map);
int		has_exit(char **map);
char	**copy_map(char **map);
void	fill_map(char **map, int x, int y);
int		is_filled(char **map);

/*---------------------------------GAME---------------------------------------*/
void	game_init(t_vars *vars, char **map);
int		key_hook(int keycode, t_vars *vars);
int		close_win(t_vars *vars);
void	display_map(t_vars *vars);

void	p_move_up(t_vars *vars);
void	p_move_down(t_vars *vars);
void	p_move_left(t_vars *vars);
void	p_move_right(t_vars *vars);

void	enemy_move(t_vars *vars, int i, int j, int *down);
int		count_line(char **map);
int		is_enemy(char c);
void	find_enemy(t_vars *vars);

void	end_game(t_vars *vars, int x, int y, int move);

void	display_end(t_vars *vars);

void	end_pos(t_vars *vars, int *x, int *y);

char	*make_screen_count(int count);

void	display_anim(t_vars *vars);

void	img_init(t_vars *vars, int width, int height);

void	img_destroy(t_vars *vars);

void	coin_anim(t_vars *vars, int x, int y);

#endif 

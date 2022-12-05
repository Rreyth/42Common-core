/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:40 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 21:29:30 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

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

#endif

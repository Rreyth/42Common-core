/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:36:49 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 21:10:36 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_args(int ac, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ac == 1)
		parse_error(0);
	if (ac > 2)
		parse_error(1);
	if (len < 5 || ft_strncmp(&file[len - 4], ".ber", 4))
		parse_error(3);
}

void	mapchr_check(char **map, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(charset, map[i][j]))
				map_error(map);
			j++;
		}
		i++;
	}
}

void	check_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			map_error(map);
		i++;
	}
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][i - 1] != '1')
			map_error(map);
		j++;
	}
	i = 0;
	while (map[j - 1][i])
	{
		if (map[j - 1][i] != '1')
			map_error(map);
		i++;
	}
}

void	check_map(char **map)
{
	int		i;
	size_t	width;

	i = 1;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
			map_error(map);
		i++;
	}
	check_border(map);
	mapchr_check(map, "01CEP");
	if (!has_collectible(map) || !has_player(map) || !has_exit(map))
		map_error(map);
}

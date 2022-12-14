/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:42:01 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/14 18:39:24 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**copy_map(char **map)
{
	int		i;
	int		width;
	char	**tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	width = ft_strlen(map[i]) + 1;
	while (map[i])
	{
		tmp[i] = malloc(sizeof(char) * width);
		ft_strlcpy(tmp[i], map[i], width);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	fill_map(char **map, int x, int y)
{
	if (map[x][y - 1] != '1' && map[x][y - 1] != 'X')
		map[x][y - 1] = '2';
	if (map[x][y + 1] != '1' && map[x][y + 1] != 'X')
		map[x][y + 1] = '2';
	if (map[x - 1][y] != '1' && map[x - 1][y] != 'X')
		map[x - 1][y] = '2';
	if (map[x + 1][y] != '1' && map[x + 1][y] != 'X')
		map[x + 1][y] = '2';
}

int	is_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				if ((map[i][j - 1] != '2' && map [i][j - 1] != '1'
						&& map[i][j - 1] != 'X') || (map[i][j + 1] != '2'
						&& map [i][j + 1] != '1' && map[i][j + 1] != 'X')
						|| (map[i - 1][j] != '2' && map [i - 1][j] != '1'
						&& map[i - 1][j] != 'X') || (map[i + 1][j] != '2'
						&& map [i + 1][j] != '1' && map[i + 1][j] != 'X'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

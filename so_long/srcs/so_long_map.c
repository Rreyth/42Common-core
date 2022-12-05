/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:48:02 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 22:02:37 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

char	*map_read(int fd)
{
	int		ret;
	char	*tmp;
	char	*str;

	ret = 1;
	str = NULL;
	tmp = ft_calloc(2, sizeof(char));
	while (ret == 1)
	{
		ret = read(fd, tmp, 1);
		if (ret < 0)
		{
			free(tmp);
			if (str)
				free(str);
			parse_error(4);
		}
		str = so_long_join(str, tmp);
	}
	free(tmp);
	return (str);
}

void	find_path(char **map, int x, int y)
{

}

void	check_path(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				break ;
			y++;
		}
		if (y != ft_strlen(map[x]))
			break ;
		x++;
	}
	find_path(map, x, y);
}

char	**make_map(char *file)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		parse_error(4);
	str = map_read(fd);
	map = ft_split(str, '\n');
	free(str);
	check_map(map);
	check_path(map);
	return (map);
}

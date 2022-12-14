/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:48:02 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/13 19:16:10 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	char	**tmp;

	tmp = copy_map(map);
	tmp[x][y] = '2';
	while (!is_filled(tmp))
	{
		x = 0;
		while (tmp[x])
		{
			y = 0;
			while (tmp[x][y])
			{
				if (tmp[x][y] == '2')
					fill_map(tmp, x, y);
				y++;
			}
			x++;
		}
	}
	if (has_collectible(tmp) || has_exit(tmp))
	{
		ft_free_map(tmp);
		map_error(map);
	}
	ft_free_map(tmp);
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
	int		i;
	char	*str;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		parse_error(4);
	str = map_read(fd);
	while (str[i + 2])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			parse_error(2);
		}
		i++;
	}
	map = ft_split(str, '\n');
	free(str);
	check_map(map);
	check_path(map);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:39:58 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 16:57:55 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_error(int code)
{
	write(2, "Error\n", 6);
	if (code == 0)
		write(2, "Program need a '.ber' map in arg\n", 33);
	else if (code == 1)
		write(2, "Too many args\n", 14);
	else if (code == 2)
		write(2, "Invalid map\n", 12);
	else if (code == 3)
		write(2, "Map must be a '.ber' file\n", 26);
	else if (code == 4)
		write(2, "File not found\n", 15);
	exit(1);
}

void	map_error(char **map)
{
	ft_free_map(map);
	parse_error(2);
}

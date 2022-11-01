/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/29 02:13:33 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;
	int			ret;

	str = NULL;
	if (stock)
	{
		str = ft_strjoin(str, stock);
		stock = ft_realloc_stock(stock);
	}
	if (!stock)
	{
		while (!ft_find_nl(stock))
		{
			stock = ft_realloc_stock(stock);
			ret = read(fd, stock, BUFFER_SIZE);
			if (ret <= 0)
			{
				free(stock);
				if (str)
					free(str);
				return (NULL);
			}
			stock[ret] = '\0';
			str = ft_strjoin(str, stock);
			stock = ft_realloc_stock(stock);
		}
	}
	if (ret == 0 && !stock)
		return (NULL);
	return (str);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testtxt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}

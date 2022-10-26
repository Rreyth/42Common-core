/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/26 23:22:57 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	char		*str;
	static char	*stock;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (100));
	if (stock)
	{
//		printf("before rm : %s\n", stock);
		while (stock[i] && stock[i] != '\n')
		{
			str[i] = stock[i];
			i++;
		}
//		printf("i : %d\n", i);
		str[i] = stock[i];
		j = i;
		if (stock[i] == '\n')
			i++;
		ft_rm_used(stock, i);
//		printf("str : %s\n", str);
//		printf("post rm : %s\n", stock);
		if (str[j] == '\n')
			return (str);
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[ret] = '\0';
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
//	str = malloc(sizeof(char) * (i + 1));
	ft_strlcat(str, buf, i);
	j = 0;
	while (buf[i])
	{
		i++;
		j++;
	}
	stock = malloc(sizeof(char) * (j + 1));
	i -= j;
	i++;
	j = 0;
	while (buf[i])
	{
		stock[j] = buf[i];
		j++;
		i++;
	}
	stock[j] = '\0';
	if (ret == 0 && buf[i] == '\0')
	{
		free(stock);
		free(buf);
	}
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("testtxt", O_RDONLY);
/*	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
*/
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

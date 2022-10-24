/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/24 20:52:19 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	int			ret;
	static char	*buf;
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ret > 0)
		ret = read(fd, buf, BUFFER_SIZE);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	while (j <= i)
	{
		str[j] = buf[j];
		j++;
	}
	if (ret == 0 && buf[i] == '\0')
		free(buf);
	return (str);
}


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("testtxt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

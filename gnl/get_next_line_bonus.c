/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/29 02:13:33 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_start_alloc(char *s)
{
	if (s)
		free(s);
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	return (s);
}

char	*ft_stock_read(char *stock, int fd)
{
	int	ret;

	stock = ft_start_alloc(stock);
	ret = read(fd, stock, BUFFER_SIZE);
	if (ret <= 0)
	{
		free(stock);
		return (NULL);
	}
	stock[ret] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*str;

	str = NULL;
	if (stock[fd])
	{
		str = ft_strjoin(str, stock[fd]);
		stock[fd] = ft_realloc_stock(stock[fd]);
	}
	if (!stock[fd])
	{
		while (!ft_find_nl(stock[fd]))
		{
			stock[fd] = ft_stock_read(stock[fd], fd);
			if (!stock[fd])
			{
				if (str)
					free(str);
				return (NULL);
			}
			str = ft_strjoin(str, stock[fd]);
		}
		stock[fd] = ft_realloc_stock(stock[fd]);
	}
	return (str);
}

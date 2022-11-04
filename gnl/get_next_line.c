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
	static char	*stock;
	char		*str;

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
			stock = ft_stock_read(stock, fd);
			if (!stock)
			{
				if (str)
					free(str);
				return (NULL);
			}
			str = ft_strjoin(str, stock);
		}
		stock = ft_realloc_stock(stock);
	}
	return (str);
}

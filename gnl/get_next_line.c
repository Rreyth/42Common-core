/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/08 04:12:33 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_start_alloc(char **s)
{
	if (*s)
		free(*s);
	*s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*s))
	{
		*s = NULL;
		return ;
	}
}

int	ft_stock_read(char **p_stock, int fd)
{
	int	ret;

	ft_start_alloc(p_stock);
	ret = read(fd, *p_stock, BUFFER_SIZE);
	if (ret < 0)
	{
		free(*p_stock);
		*p_stock = NULL;
		return (ret);
	}
	(*p_stock)[ret] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;
	int			ret;

	ret = BUFFER_SIZE;
	str = NULL;
	if (stock)
	{
		str = ft_strjoin(str, stock);
		stock = ft_realloc_stock(stock);
	}
	if (!stock)
	{
		while (!ft_find_nl(stock) && ret == BUFFER_SIZE)
		{
			ret = ft_stock_read(&stock, fd);
			if (!stock || ret < 0)
			{
				if (str)
				{
					free(str);
					str = NULL;
				}
				return (NULL);
			}
			if (stock[0] == '\0')
				break ;
			str = ft_strjoin(str, stock);
		}
		stock = ft_realloc_stock(stock);
	}
	return (str);
}

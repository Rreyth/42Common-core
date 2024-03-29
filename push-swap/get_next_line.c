/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/30 17:40:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	ft_free_all(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

void	ft_free_one(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
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
	if (BUFFER_SIZE < 1)
		return (NULL);
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
			if (!stock || ret < 0 || (stock[0] == '\0' && !str))
				ft_free_all(&str, &stock);
			str = ft_strjoin(str, stock);
		}
		stock = ft_realloc_stock(stock);
	}
	return (str);
}

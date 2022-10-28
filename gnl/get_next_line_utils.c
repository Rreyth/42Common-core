/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:54:17 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/28 20:09:02 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	size += i + 1;
	while (i < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}*/

/*int	ft_strlen (char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

/*void	ft_rm_used(char *s, int start)
{
	int		i;

	i = 0;
	while (s[start + i] && i < start)
	{
		s[i] = s[start + i];
		i++;
	}
	s[i] = '\0';
}*/

/*int	ft_find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}*/

/*char	*ft_realloc_stock(char *s, int size)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * size);
	if (s)
	{
		while (s[i] && i < size)
		{
			new_str[i] = s[i];
			i++;
		}
		new_str = '\0';
		free(s);
	}
	return (new_str);
}*/

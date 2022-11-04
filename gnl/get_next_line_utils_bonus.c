/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:54:17 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/28 20:09:02 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	size_src;
	int	size_dst;

	i = 0;
	j = 0;
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	while (dst[i] != '\0' && i < size)
		i++;
	size_dst = i;
	if (dst[i] == '\0')
	{
		while (src[j] != '\0' && i < size)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (size_dst + size_src);
}

int	ft_find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_realloc_stock(char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	new_str = malloc(sizeof(char) * (ft_strlen(&s[i]) + 1));
	if (!new_str)
	{
		free(s);
		return (NULL);
	}
	new_str[0] = '\0';
	ft_strlcat(new_str, &s[i], ft_strlen(&s[i]) + 1);
	free(s);
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	while (s2[i] && s2[i] != '\n')
		i++;
	size = ft_strlen(s1) + i + 1;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (s1)
	{
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		free(s1);
	}
	ft_strlcat(str, s2, size);
	return (str);
}

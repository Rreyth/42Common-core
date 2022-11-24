/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:07:28 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 20:59:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	unsigned int	nb_byte;
	unsigned int	i;

	i = 0;
	nb_byte = nmemb * size;
	if (nb_byte == 0)
		return (malloc(0));
	if (nb_byte / size != nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while (i < nb_byte)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	while (i < len && s[start + i])
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

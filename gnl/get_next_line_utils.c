/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:54:17 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/26 23:01:25 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlcat(char *dst, char *src, int size)
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
}

void	ft_rm_used(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[i] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:52:32 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/28 19:47:12 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_strlcat(char *dst, char *src, int size);
void	ft_rm_used(char *s, int start);
char	*ft_realloc_stock(char *s, int size);
int		ft_find_nl(char	*s);

#endif

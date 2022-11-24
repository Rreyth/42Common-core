/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:24 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/24 23:07:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

typedef struct t_struct{
	int	*tab;
	int	max_size;
	int	size;
}	t_struct;

void		ft_check_args(int ac, char **av);
void		ft_exit_error(void);
void		ft_free_stack(t_struct s);

t_struct	ft_get_stacked(int ac, char **av);
char		*ft_join_args(int ac, char **av);
int			*ft_atoi_tab(char **tab);
int			ft_atoi(const char *nptr);
int			ft_tab_len(char **tab);

char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, int start, size_t len);

int			ft_strlen(char const *s);
int			ft_args_len(int ac, char **av);
#endif

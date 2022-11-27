/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:24 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/11/27 22:42:05 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct{
	int	*tab;
	int	max_size;
	int	size;
}	t_struct;

/*---------------------------------Parsing------------------------------------*/
/*---------------------------------Error_Check--------------------------------*/
void		ft_check_args(int ac, char **av);
void		ft_exit_error(void);
void		ft_free_error(t_struct **s);
void		ft_free_stack(t_struct **s);
void		ft_atoi_error(t_struct **s, char **tab);
void		ft_check_duplicate(t_struct **stack);

/*---------------------------------Stacking-----------------------------------*/
t_struct	*ft_get_stacked(int ac, char **av);
char		*ft_join_args(int ac, char **av);
void		ft_atoi_tab(char **tab, t_struct **stack);
int			ft_atoi(const char *nptr, t_struct **stack, char **tab);
char		**ft_split(char const *s, char c);

/*---------------------------------Utils--------------------------------------*/
int			ft_tab_len(char **tab);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, int start, size_t len);
int			ft_strlen(char const *s);
int			ft_args_len(int ac, char **av);
void		normalize(t_struct *stack);

/*---------------------------------Sorting------------------------------------*/
/*---------------------------------Sort_Utils---------------------------------*/
void		swap(t_struct *stack, char name);
void		dual_swap(t_struct *stack_a, t_struct *stack_b);
void		rotate(t_struct *stack, char name);
void		dual_rotate(t_struct *stack_a, t_struct *stack_b);
void		reverse_rotate(t_struct *stack, char name);
void		dual_reverse_rotate(t_struct *stack_a, t_struct *stack_b);
void		push(t_struct *stack_a, t_struct *stack_b, char name);
int			ft_is_sorted(t_struct *stack);

/*---------------------------------Sort_algo----------------------------------*/
void		ft_launch_sort(t_struct *stack_a);
void		small_sort(t_struct *stack);
void		global_sort(t_struct *stack_a);

#endif

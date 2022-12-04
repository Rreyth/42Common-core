/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:29:21 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/03 17:45:04 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
void		checker_error(char *str, t_struct *stack_a, t_struct *stack_b);

/*---------------------------------Stacking-----------------------------------*/
t_struct	*args_to_stack(int ac, char **av);
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

/*---------------------------------Checking-----------------------------------*/
/*---------------------------------Checking_Utils-----------------------------*/
void		checker_swap(t_struct *stack);
void		checker_dual_swap(t_struct *stack_a, t_struct *stack_b);
void		checker_rotate(t_struct *stack);
void		checker_dual_rotate(t_struct *stack_a, t_struct *stack_b);
void		checker_reverse_rotate(t_struct *stack);
void		checker_dual_reverse_rotate(t_struct *stack_a, t_struct *stack_b);
void		checker_push(t_struct *stack_a, t_struct *stack_b, char name);
int			ft_is_sort(t_struct *stack);

/*---------------------------------Get_Next_Line------------------------------*/

# define BUFFER_SIZE 1

void		ft_free_all(char **s1, char **s2);
void		ft_free_one(char **s);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_realloc_stock(char *s);
int			ft_strlcat(char *dst, char *src, int size);
int			ft_find_nl(char *s);

#endif

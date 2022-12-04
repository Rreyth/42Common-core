/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:14:37 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/03 17:51:17 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if ((s1[i] == '\0' || s1[i] == '\n') && s2[i] != '\0')
		return (str1[i] - str2[i]);
	return (0);
}

void	check_instructions(t_struct *stack_a, t_struct *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", ft_strlen(str) - 1))
		checker_swap(stack_a);
	else if (!ft_strncmp(str, "sb", ft_strlen(str) - 1))
		checker_swap(stack_b);
	else if (!ft_strncmp(str, "ss", ft_strlen(str) - 1))
		checker_dual_swap(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa", ft_strlen(str) - 1))
		checker_push(stack_a, stack_b, 'a');
	else if (!ft_strncmp(str, "pb", ft_strlen(str) - 1))
		checker_push(stack_a, stack_b, 'b');
	else if (!ft_strncmp(str, "ra", ft_strlen(str) - 1))
		checker_rotate(stack_a);
	else if (!ft_strncmp(str, "rb", ft_strlen(str) - 1))
		checker_rotate(stack_b);
	else if (!ft_strncmp(str, "rr", ft_strlen(str) - 1))
		checker_dual_rotate(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra", ft_strlen(str) - 1))
		checker_reverse_rotate(stack_a);
	else if (!ft_strncmp(str, "rrb", ft_strlen(str) - 1))
		checker_reverse_rotate(stack_b);
	else if (!ft_strncmp(str, "rrr", ft_strlen(str) - 1))
		checker_dual_reverse_rotate(stack_a, stack_b);
	else
		checker_error(str, stack_a, stack_b);
}

t_struct	*init_stack(t_struct *stack_a)
{
	t_struct	*stack_b;

	stack_b = malloc(sizeof(t_struct));
	if (!stack_b)
		ft_free_error(&stack_a);
	stack_b->tab = ft_calloc(stack_a->max_size, sizeof(int));
	if (!stack_b->tab)
	{
		ft_free_stack(&stack_b);
		ft_free_error(&stack_a);
	}
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	return (stack_b);
}

int	main(int argc, char **argv)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	char		*str;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = args_to_stack(argc, argv);
	stack_b = init_stack(stack_a);
	str = get_next_line(0);
	while (str != NULL)
	{
		check_instructions(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
	if (ft_is_sort(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

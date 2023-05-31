/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:38:43 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/25 19:39:28 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_exit(char *str)
{
	if (!ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
	{
		ft_printf_fd(1, "exit\n");
		exit(0);
	}
}

void	check_chevron(char *str)
{
	char	*start_here;
	int		i;

	i = 0;
	start_here = ft_strchr(str, '<');
	while (start_here && start_here[i] && start_here[i] == '<')
		i++;
	if (i == 1)
		ft_printf_fd(1, "INFILE\n");
	else if (i == 2)
		ft_printf_fd(1, "HEREDOC\n");
//	else if (i == 3)
//		gestion <<<
	else if (i > 3) //retirer quand check syntax up
		ft_printf_fd(2, "syntax error\n");
}

void	parse_line(char *line)
{
	char	*str;

	str = ft_strtrim(line, " \t");
//	check syntax (more than 3 < / more than 2 >)
	is_exit(str); //is exit a modifier avec le builtin
	check_chevron(str);
//	if | pipe
//	else cmd
	free(str);
}

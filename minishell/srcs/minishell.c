/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:16:21 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/25 16:52:02 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_screen(char **envp)
{
	pid_t	pid;
	char	*args[3];

	args[0] = "clear";
	args[1] = "-x";
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve("/usr/bin/clear", args, envp);
		perror(0);
	}
	waitpid(pid, 0, 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;

	(void) argv;
	if (argc != 1)
	{
		ft_printf_fd(2, "Too many arguments\n");
		return (2);
	}
	clear_screen(envp);
	str = readline("PROMPT% ");
	while (str)
	{
		if (*str)
		{
			add_history(str);
			parse_line(str);
		}
		free(str);
		str = readline("PROMPT% ");
	}
	if (!str)
		ft_printf_fd(1, "exit\n");
	if (str)
		free(str);
	rl_clear_history();
	return (0);
}

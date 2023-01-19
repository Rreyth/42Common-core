/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:28:06 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/19 23:02:12 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	launch_heredoc(int ac, char **av, char **envp, t_pipex *pipex)
{
	int		status;
	char	*str;

	str = get_next_line(0);
	pipe(pipex->fd_pipe);
	while (str)
	{
		if (!ft_strncmp(str, av[2], ft_strlen(av[2]))
			&& ft_strlen(str) == ft_strlen(av[2]))
			break ;
		ft_putstr_fd(str, pipex->fd_pipe[1]);
		write(pipex->fd_pipe[1], "\n", 1);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
	status = multi_pipe(ac, av, envp, pipex);
	return (status);
}

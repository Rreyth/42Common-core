/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:32:37 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/19 21:42:54 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	exec_odd_cmd(t_pipex *pipex, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		dup_close(pipex->fd_pipe, pipex->fd_pipe2);
		if (pipex->path)
		{
			execve(pipex->path, pipex->args, envp);
			perror(0);
		}
		else
			ft_printf_fd(2, "command not found: %s\n", pipex->args[0]);
		free(pipex->path);
		ft_free_tab(pipex->args);
		exit(2);
	}
	waitpid(pid, &status, 0);
	return (status >> 8);
}

int	exec_even_cmd(t_pipex *pipex, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		dup_close(pipex->fd_pipe2, pipex->fd_pipe);
		if (pipex->path)
		{
			execve(pipex->path, pipex->args, envp);
			perror(0);
		}
		else
			ft_printf_fd(2, "command not found: %s\n", pipex->args[0]);
		free(pipex->path);
		ft_free_tab(pipex->args);
		exit(2);
	}
	waitpid(pid, &status, 0);
	return (status >> 8);
}

int	launch_last_cmd(int ac, char **av, t_pipex *pipex, char **envp)
{
	int	status;

	pipex->args = make_args(av[ac - 2]);
	pipex->path = find_path(pipex->args[0], envp);
	status = test_open(av[ac - 1], 1, pipex);
	if (pipex->fd != -1 && (ac - 2) % 2 == 0)
	{
		close(pipex->fd_pipe2[1]);
		status = exec_last_cmd(pipex, envp, pipex->fd_pipe2);
		close(pipex->fd_pipe2[0]);
	}
	else if (pipex->fd != -1 && (ac - 2) % 2 != 0)
	{
		close(pipex->fd_pipe[1]);
		status = exec_last_cmd(pipex, envp, pipex->fd_pipe);
		close(pipex->fd_pipe[0]);
	}
	if (pipex->fd > 2)
		close(pipex->fd);
	free(pipex->path);
	ft_free_tab(pipex->args);
	return (status);
}

int	launch_loop_cmd(int i, t_pipex *pipex, char **envp)
{
	int	status;

	status = 0;
	if (i == 2 && pipex->fd != -1)
	{
		status = exec_first_cmd(pipex, envp);
		close(pipex->fd);
	}
	else if (i % 2 == 0 && i != 2)
	{
		close(pipex->fd_pipe2[1]);
		status = exec_even_cmd(pipex, envp);
		close(pipex->fd_pipe2[0]);
	}
	else if (i % 2 != 0)
	{
		close(pipex->fd_pipe[1]);
		status = exec_odd_cmd(pipex, envp);
		close(pipex->fd_pipe[0]);
	}
	return (status);
}

int	multi_pipe(int ac, char **av, char **envp, t_pipex *pipex)
{
	int	i;
	int	status;

	if (pipex->here_doc == 0)
	{
		i = 2;
		status = test_open(av[1], 0, pipex);
	}
	else
		i = 3;
	while (i < ac - 2)
	{
		if (i % 2 == 0)
			pipe(pipex->fd_pipe);
		else
			pipe(pipex->fd_pipe2);
		pipex->args = make_args(av[i]);
		pipex->path = find_path(pipex->args[0], envp);
		status = launch_loop_cmd(i, pipex, envp);
		free(pipex->path);
		ft_free_tab(pipex->args);
		i++;
	}
	status = launch_last_cmd(ac, av, pipex, envp);
	return (status);
}

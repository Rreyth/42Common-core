/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:25:41 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/19 22:31:43 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	exec_first_cmd(t_pipex *pipex, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->fd_pipe[1], 1);
		close(pipex->fd_pipe[0]);
		close(pipex->fd_pipe[1]);
		dup2(pipex->fd, 0);
		close(pipex->fd);
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

int	exec_last_cmd(t_pipex *pipex, char **envp, int *fd_pipe)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		dup2(pipex->fd, 1);
		close(pipex->fd);
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

int	launch_cmd(int ac, char **av, char **envp, t_pipex *pipex)
{
	int		status;

	pipex->args = make_args(av[2]);
	pipex->path = find_path(pipex->args[0], envp);
	pipe(pipex->fd_pipe);
	status = test_open(av[1], 0, pipex);
	if (pipex->fd != -1)
		status = exec_first_cmd(pipex, envp);
	if (pipex->fd > 2)
		close(pipex->fd);
	ft_free_tab(pipex->args);
	free(pipex->path);
	pipex->args = make_args(av[3]);
	pipex->path = find_path(pipex->args[0], envp);
	status = test_open(av[ac - 1], 1, pipex);
	close(pipex->fd_pipe[1]);
	if (pipex->fd != -1)
		status = exec_last_cmd(pipex, envp, pipex->fd_pipe);
	close(pipex->fd_pipe[0]);
	if (pipex->fd > 2)
		close(pipex->fd);
	ft_free_tab(pipex->args);
	free(pipex->path);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	status = 0;
	pipex.here_doc = 0;
	if (argc >= 5)
		pipex.here_doc = is_here_doc(argv[1]);
	if (pipex.here_doc && argc >= 6)
		status = launch_heredoc(argc, argv, envp, &pipex);
	else if (argc == 5 && !pipex.here_doc)
		status = launch_cmd(argc, argv, envp, &pipex);
	else if (argc > 5 && !pipex.here_doc)
		status = multi_pipe(argc, argv, envp, &pipex);
	else
		ft_printf_fd(2, "Invalid number of arguments\n");
	return (status);
}

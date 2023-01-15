/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:25:41 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/15 13:22:28 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_first_cmd(int *fd_pipe, int fd, char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		dup2(fd, 0);
		close(fd);
		if (path)
			execve(path, args, NULL);
		ft_printf_fd(2, "command not found: %s\n", args[0]);
		free(path);
		ft_free_tab(args);
		exit(2);
	}
}

void	exec_sec_cmd(int *fd_pipe, int fd, char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		dup2(fd, 1);
		close(fd);
		if (path)
			execve(path, args, NULL);
		ft_printf_fd(2, "command not found: %s\n", args[0]);
		free(path);
		ft_free_tab(args);
		exit(2);
	}
}

void	launch_cmd(int ac, char **av, char **envp)
{
	int		fd_pipe[2];
	int		fd;
	char	**args;
	char	*path;

	args = ft_split(av[2], ' ');
	path = find_path(args[0], envp);
	pipe(fd_pipe);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_printf_fd(2, "no such file or directory: %s\n", av[1]);
	else
		exec_first_cmd(fd_pipe, fd, path, args);
	close(fd);
	ft_free_tab(args);
	free(path);
	args = ft_split(av[3], ' ');
	path = find_path(args[0], envp);
	fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	exec_sec_cmd(fd_pipe, fd, path, args);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd);
	ft_free_tab(args);
	free(path);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf_fd(2, "invalid number of args\n");
		return (0);
	}
	launch_cmd(argc, argv, envp);
	return (0);
}

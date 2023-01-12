/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:25:41 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/12 02:08:39 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	find_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			return (i);
		i++;
	}
	return (-1);
}

char	*find_path(int ac, char **av, char **envp)
{
	int		i;
	char	**tab;
	char	**cmd;
	char	*path;

	(void) ac;
	i = find_env(envp);
	tab = ft_split(envp[i], ':');
	cmd = ft_split(av[2], ' ');
	i = 0;
	while (tab[i])
	{
		tab[i] = gnl_strjoin(tab[i], "/");
		tab[i] = gnl_strjoin(tab[i], cmd[0]);
		if (!access(tab[i], X_OK))
		{
			path = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));
			ft_strlcpy(path, tab[i], ft_strlen(tab[i]) + 1);
			break ;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (cmd[1])
		path = gnl_strjoin(path, cmd[1]);
	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	free(tab);
	return (path);
}

void	launch(int ac, char **av, char **envp)
{
//	char	*path;
	pid_t	pid;
	char	*cmd[] = {"cat", "-e", "ui", NULL};
	
	(void) ac;
	(void) av;
//	path = find_path(ac, av, envp);
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/cat", cmd, envp);
//	free(path);
//	fd = open(av[1], O_RDONLY);
//	if (fd == -1)
//		ft_printf("no such file or directory : %s\n", av[1]);
//	execve("/usr/bin/cat", av, envp);
//	perror("execve");
}

void	test_outfile(void)
{
	char *args[] = {"cat", "-e", "ui", NULL};
	int fd;

	fd = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 777);
	dup2(fd, 1);
	close(fd);
	execve("/usr/bin/cat", args, NULL);
}

void	test_pipe(void)
{
	int	fd[2];
	int	fd_in;
	int	fd_out;
	char	*args1[] = {"cat", "-e", NULL};
	char	*args2[] = {"ls", "-la", NULL};

	pipe(fd);
	fd_in = open("ui", O_RDONLY);
	fd_out = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fork() == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		dup2(fd_in, 0);
		close(fd_in);
		execve("/usr/bin/cat", args1, NULL);
	}
	else if (fork() == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		dup2(fd_out, 1);
		close(fd_out);
		execve("/usr/bin/ls", args2, NULL);
	}
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("invalid number of args\n");
		return (0);
	}
	(void) argv;
	(void) envp;
//	check_args(argc, argv);
//	launch(argc, argv, envp);
//	test_outfile();
	test_pipe();
	return (0);
}

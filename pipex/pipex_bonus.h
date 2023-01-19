/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:27:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/19 22:29:13 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex {
	int		fd_pipe[2];
	int		fd_pipe2[2];
	int		fd;
	int		here_doc;
	char	*path;
	char	**args;
}			t_pipex;

/*---------------------------------UTILS--------------------------------------*/
char	*find_path(char *cmd, char **envp);
char	**make_args(char *cmd);
int		test_open(char *file, int phase, t_pipex *pipex);
int		is_here_doc(char *str);
void	ft_free_tab(char **tab);
void	dup_close(int *fd, int *fd2);

/*---------------------------------EXEC---------------------------------------*/
int		exec_first_cmd(t_pipex *pipex, char **envp);
int		exec_last_cmd(t_pipex *pipex, char **envp, int *fd_pipe);

/*---------------------------------BONUS--------------------------------------*/
int		multi_pipe(int ac, char **av, char **envp, t_pipex *pipex);
int		launch_heredoc(int ac, char **av, char **envp, t_pipex *pipex);

#endif

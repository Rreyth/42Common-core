/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:27:47 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/18 21:38:03 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex {
	int		fd_pipe[2];
	int		fd;
	char	*path;
	char	**args;
}			t_pipex;

char	*find_path(char *cmd, char **envp);

char	**make_args(char *cmd);

int		test_open(char *file, int phase, t_pipex *pipex);

void	ft_free_tab(char **tab);

#endif

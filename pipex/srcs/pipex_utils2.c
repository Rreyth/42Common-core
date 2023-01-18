/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:01:01 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/18 21:40:00 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	test_open(char *file, int phase, t_pipex *pipex)
{
	if (phase == 0)
	{
		pipex->fd = open(file, O_RDONLY);
		if (pipex->fd == -1 && !access(file, F_OK))
			ft_printf_fd(2, "permission denied: %s\n", file);
		else if (pipex->fd == -1)
			ft_printf_fd(2, "no such file or directory: %s\n", file);
	}
	if (phase == 1)
	{
		pipex->fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->fd == -1 && access(file, W_OK))
			ft_printf_fd(2, "permission denied: %s\n", file);
		else if (pipex->fd == -1)
			ft_printf_fd(2, "is a directory: %s\n", file);
	}
	if (pipex->fd == -1)
		return (1);
	return (0);
}

void	del_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

char	**make_args(char *cmd)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	args = ft_split(cmd, ' ');
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '\'')
				del_char(&args[i][j]);
			j++;
		}
		i++;
	}
	return (args);
}

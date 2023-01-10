/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:25:41 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/11 00:25:34 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>

void	launch(int ac, char **av)
{
	int	fd;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_printf("no such file or directory : %s\n", av[1]);
	execve(const char *__path, char *const *__argv, char *const *__envp);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("invalid number of args\n");
		return (0);
	}
//	check_cmd(argc, argv);
	launch(argc, argv);
	return (0);
}

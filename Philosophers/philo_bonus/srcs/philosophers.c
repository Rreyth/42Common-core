/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:26:20 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/25 13:38:06 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	manage_philo(t_philo *philo, t_data *data)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			launch_routine(&philo[i]);
		i++;
	}
	pid = fork();
	if (pid == 0)
		check_hungry(data);
	sem_wait(data->dead);
	i = 0;
	while (i < data->nb_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	kill(pid, SIGKILL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (2);
	}
	philo = parse_init(argc, argv, &data);
	if (!philo)
		return (2);
	manage_philo(philo, &data);
	clear_data(&data, philo);
	free(philo);
	return (0);
}

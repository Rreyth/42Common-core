/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:26:20 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/30 13:49:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	manage_philo(t_philo *philo, t_data *data)
{
	int			i;
	pthread_t	tid;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].tid, NULL, launch_routine, &philo[i]);
		i++;
	}
	pthread_create(&tid, NULL, supervisor, philo);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	pthread_join(tid, NULL);
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
	if (philo)
		free(philo);
	clear_data(&data);
	return (0);
}

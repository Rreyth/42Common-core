/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:07:12 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/27 18:23:35 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		if (result * negative > 2147483647)
			return (-1);
		if (result * negative < -2147483648)
			return (-1);
		i++;
	}
	return (result * negative);
}

int	invalid_arg(int ac, t_data *data)
{
	if (data->nb_philo <= 0 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0
		|| (ac == 6 && data->nb_eat <= 0))
	{
		write(2, "Invalid arguments\n", 18);
		return (2);
	}
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
	{
		write(2, "malloc error\n", 13);
		return (2);
	}
	while (i < data->nb_philo)
	{
		philo[i].pos = i;
		philo[i].nb_eat = data->nb_eat;
		philo[i].data = data;
		i++;
	}
	return (0);
}

int	parse_init(int ac, char **av, t_data *data, t_philo *philo)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->is_dead = 0;
	data->test = 0;
	if (ac == 6)
		data->nb_eat = ft_atoi(av[5]);
	else
		data->nb_eat = -2;
	if (invalid_arg(ac, data))
		return (2);
	if (init_philo(philo, data))
		return (2);
	pthread_mutex_init(&data->test_mutex, NULL);
	return (0);
}

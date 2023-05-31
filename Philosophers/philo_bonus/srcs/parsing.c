/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:07:12 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/25 13:46:13 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		return (-1);
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		if (result > 2147483647)
			return (-1);
		i++;
	}
	if (nptr[i])
		return (-1);
	return (result);
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

t_philo	*init_philo(t_data *data)
{
	t_philo			*philo;
	struct timeval	time;
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	gettimeofday(&time, NULL);
	while (i < data->nb_philo)
	{
		philo[i].pos = i;
		philo[i].nb_eat = data->nb_eat;
		philo[i].finished = 0;
		if (philo[i].nb_eat == -2)
			philo[i].finished = 1;
		philo[i].data = data;
		philo[i].start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		philo[i].last_eat = 0;
		i++;
	}
	return (philo);
}

void	init_sem(t_data *data, t_philo *philo)
{
	int		i;
	char	*name;

	i = 0;
	while (i < data->nb_philo)
	{
		name = ft_itoa(philo[i].pos);
		philo[i].var_sem = sem_open(name, O_CREAT, 0644, 1);
		sem_unlink(name);
		free(name);
		i++;
	}
	data->print_sem = sem_open("print", O_CREAT, 0644, 1);
	data->fork = sem_open("fork", O_CREAT, 0644, data->nb_philo);
	data->wait_fork = sem_open("wait", O_CREAT, 0644, 1);
	data->dead = sem_open("dead", O_CREAT, 0644, 0);
	data->eat = sem_open("eat", O_CREAT, 0644, 0);
	sem_unlink("print");
	sem_unlink("fork");
	sem_unlink("wait");
	sem_unlink("dead");
	sem_unlink("eat");
}

t_philo	*parse_init(int ac, char **av, t_data *data)
{
	t_philo	*philo;

	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->end = 0;
	if (ac == 6)
		data->nb_eat = ft_atoi(av[5]);
	else
		data->nb_eat = -2;
	if (invalid_arg(ac, data))
		return (NULL);
	philo = init_philo(data);
	if (!philo)
		return (NULL);
	init_sem(data, philo);
	return (philo);
}

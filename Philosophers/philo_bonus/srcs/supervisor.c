/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:01:02 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/31 19:27:00 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_eat_nb(t_philo *philo)
{
	sem_wait(philo->var_sem);
	if (philo->nb_eat <= 0 && !philo->finished)
	{
		sem_post(philo->data->eat);
		philo->finished = 1;
	}
	sem_post(philo->var_sem);
}

void	check_death(t_philo *philo)
{
	int				i;
	long			curr;
	struct timeval	time;

	i = 0;
	gettimeofday(&time, NULL);
	curr = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (curr > philo->start + philo->last_eat + philo->data->time_die)
	{
		sem_wait(philo->var_sem);
		philo->data->end = 1;
		sem_post(philo->var_sem);
		sem_wait(philo->data->print_sem);
		curr = set_timer(&philo[i]);
		printf("-%ld-\t%d died\n", curr, philo[i].pos + 1);
		sem_post(philo->data->dead);
	}
}

void	*supervisor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	while (!philo->data->end)
	{
		if (philo->data->nb_eat != -2)
			check_eat_nb(philo);
		if (!philo->data->end)
			check_death(philo);
	}
	return (NULL);
}

void	check_hungry(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		sem_wait(data->eat);
		i++;
	}
	sem_post(data->dead);
	exit(0);
}

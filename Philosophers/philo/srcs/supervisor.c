/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:01:02 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/29 20:56:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_eat_nb(t_philo *philo)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < philo[0].data->nb_philo)
	{
		if (philo[i].nb_eat <= 0)
			finished++;
		i++;
	}
	if (finished == philo[0].data->nb_philo)
		philo[0].data->end = 1;
}

void	check_death(t_philo *philo)
{
	int				i;
	long			curr;
	struct timeval	time;

	i = 0;
	gettimeofday(&time, NULL);
	curr = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (i < philo->data->nb_philo)
	{
		if (curr > philo[i].start + philo[i].last_eat + philo[i].data->time_die)
		{
			philo[i].data->end = 1;
			pthread_mutex_lock(&philo[i].data->print_mutex);
			curr = set_timer(&philo[i]);
			printf("-%ld-\t%d died\n", curr, philo[i].pos + 1);
			pthread_mutex_unlock(&philo[i].data->print_mutex);
			return ;
		}
		i++;
	}
}

void	*supervisor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	while (!philo->data->end)
	{
		if (philo[0].data->nb_eat != -2)
			check_eat_nb(philo);
		check_death(philo);
	}
	return (NULL);
}

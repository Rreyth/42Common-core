/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:33:00 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/25 13:15:17 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_sleep(t_philo *philo, int time)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->var_mtx);
	while (!philo->data->end && i < time)
	{
		pthread_mutex_unlock(&philo->data->var_mtx);
		usleep(50000);
		i += 50;
		pthread_mutex_lock(&philo->data->var_mtx);
	}
	pthread_mutex_unlock(&philo->data->var_mtx);
}

void	think_routine(t_philo *philo)
{
	display_act(philo, 0);
}

void	sleep_routine(t_philo *philo)
{
	display_act(philo, 1);
	philo_sleep(philo, philo->data->time_sleep);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->pos]);
	display_act(philo, 2);
	if (!only_philo(philo))
	{
		if (philo->pos + 1 != philo->data->nb_philo)
			pthread_mutex_lock(&philo->data->fork[philo->pos + 1]);
		else
			pthread_mutex_lock(&philo->data->fork[0]);
		pthread_mutex_lock(&philo->data->var_mtx);
		philo->last_eat = set_timer(philo);
		pthread_mutex_unlock(&philo->data->var_mtx);
		display_act(philo, 2);
		display_act(philo, 3);
		pthread_mutex_lock(&philo->data->var_mtx);
		philo->nb_eat--;
		pthread_mutex_unlock(&philo->data->var_mtx);
		philo_sleep(philo, philo->data->time_eat);
		if (philo->pos + 1 != philo->data->nb_philo)
			pthread_mutex_unlock(&philo->data->fork[philo->pos + 1]);
		else
			pthread_mutex_unlock(&philo->data->fork[0]);
	}
	pthread_mutex_unlock(&philo->data->fork[philo->pos]);
}

void	*launch_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->pos % 2 != 0)
		usleep(2000);
	pthread_mutex_lock(&philo->data->var_mtx);
	while (!philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->var_mtx);
		think_routine(philo);
		eat_routine(philo);
		sleep_routine(philo);
		pthread_mutex_lock(&philo->data->var_mtx);
	}
	pthread_mutex_unlock(&philo->data->var_mtx);
	return (NULL);
}

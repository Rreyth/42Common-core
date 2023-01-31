/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:33:00 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/31 19:40:36 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_sleep(t_philo *philo, int time)
{
	int	i;

	i = 0;
	while (!philo->data->end && i < time)
	{
		usleep(50000);
		i += 50;
	}
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
	sem_wait(philo->data->fork);
	display_act(philo, 2);
	if (!only_philo(philo))
	{
		sem_wait(philo->data->fork);
		philo->last_eat = set_timer(philo);
		display_act(philo, 2);
		display_act(philo, 3);
		sem_wait(philo->var_sem);
		philo->nb_eat--;
		sem_post(philo->var_sem);
		philo_sleep(philo, philo->data->time_eat);
		sem_post(philo->data->fork);
	}
	sem_post(philo->data->fork);
}

void	launch_routine(t_philo *philo)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, supervisor, philo);
	pthread_detach(tid);
//	if (philo->pos % 2 != 0)
//		usleep(2000);
	sem_wait(philo->var_sem);
	while (!philo->data->end)
	{
		sem_post(philo->var_sem);
		think_routine(philo);
		eat_routine(philo);
		sleep_routine(philo);
		sem_wait(philo->var_sem);
	}
	sem_post(philo->var_sem);
	exit (0);
}

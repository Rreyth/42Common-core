/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:33:00 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/29 20:33:37 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	think_routine(t_philo *philo)
{
	long			timer;

	pthread_mutex_lock(&philo->data->print_mutex);
	timer = set_timer(philo);
	printf("-%ld-\t%d is thinking\n", timer, philo->pos + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	sleep_routine(t_philo *philo)
{
	long			timer;

	pthread_mutex_lock(&philo->data->print_mutex);
	timer = set_timer(philo);
	printf("-%ld-\t%d is sleeping\n", timer, philo->pos + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_sleep * 1000);
}

void	eat_routine(t_philo *philo)
{
	long	timer;

	if (philo->data->nb_philo == 1)
		wait_death(philo);
	pthread_mutex_lock(&philo->data->fork[philo->pos]);
	pthread_mutex_lock(&philo->data->print_mutex);
	timer = set_timer(philo);
	printf("-%ld-\t%d has taken a fork\n", timer, philo->pos + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
	if (philo->pos + 1 != philo->data->nb_philo)
		pthread_mutex_lock(&philo->data->fork[philo->pos + 1]);
	else
		pthread_mutex_lock(&philo->data->fork[0]);
	pthread_mutex_lock(&philo->data->print_mutex);
	timer = set_timer(philo);
	printf("-%ld-\t%d has taken a fork\n", timer, philo->pos + 1);
	printf("-%ld-\t%d is eating\n", timer, philo->pos + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->last_eat = timer;
	philo->nb_eat--;
	usleep(philo->data->time_eat * 1000);
	if (philo->pos + 1 != philo->data->nb_philo)
		pthread_mutex_unlock(&philo->data->fork[philo->pos + 1]);
	else
		pthread_mutex_unlock(&philo->data->fork[0]);
	pthread_mutex_unlock(&philo->data->fork[philo->pos]);
}

void	*launch_routine(void *p)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) p;
	while (!philo->data->end)
	{
		think_routine(philo);
		eat_routine(philo);
		sleep_routine(philo);
		i++;
	}
	return (NULL);
}

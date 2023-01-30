/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:24:44 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/30 13:48:05 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	only_philo(t_philo *philo)
{
	if (philo->data->nb_philo > 1)
		return (0);
	while (!philo->data->end)
	{
	}
	return (1);
}

long	set_timer(t_philo *philo)
{
	struct timeval	time;
	long			current;
	long			timer;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	timer = current - philo->start;
	return (timer);
}

void	display_act(t_philo *philo, int act)
{
	long	timer;

	pthread_mutex_lock(&philo->data->var_mtx);
	if (philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->var_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->data->var_mtx);
	pthread_mutex_lock(&philo->data->print_mtx);
	timer = set_timer(philo);
	if (act == 0)
		printf("-%ld-\t%d is thinking\n", timer, philo->pos + 1);
	if (act == 1)
		printf("-%ld-\t%d is sleeping\n", timer, philo->pos + 1);
	if (act == 2)
		printf("-%ld-\t%d has taken a fork\n", timer, philo->pos + 1);
	if (act == 3)
		printf("-%ld-\t%d is eating\n", timer, philo->pos + 1);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

void	clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	if (data->fork)
		free(data->fork);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->var_mtx);
}

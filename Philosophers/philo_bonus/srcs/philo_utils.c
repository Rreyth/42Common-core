/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:24:44 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/02/25 13:45:05 by tdhaussy         ###   ########.fr       */
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

	sem_wait(philo->var_sem);
	if (philo->data->end)
	{
		sem_post(philo->var_sem);
		return ;
	}
	sem_post(philo->var_sem);
	sem_wait(philo->data->print_sem);
	timer = set_timer(philo);
	if (act == 0)
		printf("-%ld-\t%d is thinking\n", timer, philo->pos + 1);
	if (act == 1)
		printf("-%ld-\t%d is sleeping\n", timer, philo->pos + 1);
	if (act == 2)
		printf("-%ld-\t%d has taken a fork\n", timer, philo->pos + 1);
	if (act == 3)
		printf("-%ld-\t%d is eating\n", timer, philo->pos + 1);
	sem_post(philo->data->print_sem);
}

void	clear_data(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		sem_close(philo[i].var_sem);
		i++;
	}
	sem_close(data->print_sem);
	sem_close(data->fork);
	sem_close(data->dead);
	sem_close(data->eat);
	sem_close(data->wait_fork);
}

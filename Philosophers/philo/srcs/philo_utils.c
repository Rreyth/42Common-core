/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:24:44 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/29 20:31:00 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait_death(t_philo *philo)
{
	(void) philo;
	printf("waiting for ded");
	while (1);
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

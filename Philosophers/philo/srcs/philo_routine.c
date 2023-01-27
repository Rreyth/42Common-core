/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:33:00 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/27 23:38:11 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*launch_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	printf("pos = %d, start = %ld\n", philo->pos, philo->start_time.tv_sec);
//	while (i < philo->nb_eat) // + not dead ?
//	{
		//think
		//eat
		//sleep
//	}
//	pthread_mutex_lock(&philo->data->test_mutex);
//	philo->data->test++;
//	pthread_mutex_unlock(&philo->data->test_mutex);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:26:20 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/27 18:26:57 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
/*
void	*routined(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	pthread_mutex_lock(&p->data->test_mutex);
	p->data->test++;
	pthread_mutex_unlock(&p->data->test_mutex);
	return (NULL);
}
*/
void	manage_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].tid, NULL, launch_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (2);
	}
	if (parse_init(argc, argv, &data, philo))
		return (2);
	//launch + join thread fct
	manage_philo(philo, &data);
	if (philo)
		free(philo);
	printf("test = %d\n", data.test);
	pthread_mutex_destroy(&data.test_mutex);
	// free
	return (0);
}

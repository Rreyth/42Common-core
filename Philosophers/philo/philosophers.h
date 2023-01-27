/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:25:07 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/27 18:28:28 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	int		is_dead;
	int		test;
	pthread_mutex_t	test_mutex;
}			t_data;

typedef struct s_philo
{
	int			pos;
	int			nb_eat;
	pthread_t	tid;
	t_data		*data;
	//fork left
	//fork right
}			t_philo;

/*----------------------------------------------------------------------------*/

int		parse_init(int ac, char **av, t_data *data, t_philo *philo);

void	*launch_routine(void *p);

//void	free_philo(t_data *data);

#endif

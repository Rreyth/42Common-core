/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:25:07 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/29 20:31:10 by tdhaussy         ###   ########.fr       */
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
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				end;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork;
}			t_data;

typedef struct s_philo
{
	int			pos;
	int			nb_eat;
	long		start;
	long		last_eat;
	t_data		*data;
	pthread_t	tid;
}			t_philo;

/*----------------------------------------------------------------------------*/

t_philo	*parse_init(int ac, char **av, t_data *data);

void	*launch_routine(void *p);

void	*supervisor(void *p);

void	wait_death(t_philo *philo);

long	set_timer(t_philo *philo);

//void	free_philo(t_data *data);

#endif

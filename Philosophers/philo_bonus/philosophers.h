/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:25:07 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/01/31 18:49:38 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_data
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	int		end;
	sem_t	*print_sem;
	sem_t	*fork;
	sem_t	*dead;
	sem_t	*eat;
}			t_data;

typedef struct s_philo
{
	int		pos;
	int		nb_eat;
	int		finished;
	long	start;
	long	last_eat;
	t_data	*data;
	sem_t	*var_sem;
	pid_t	pid;
}			t_philo;

/*----------------------------------------------------------------------------*/

t_philo	*parse_init(int ac, char **av, t_data *data);

void	launch_routine(t_philo *philo);

void	display_act(t_philo *philo, int act);

void	*supervisor(void *p);

void	check_hungry(t_data *data);

void	clear_data(t_data *data, t_philo *philo);

int		only_philo(t_philo *philo);

long	set_timer(t_philo *philo);

char	*ft_itoa(int n);

#endif

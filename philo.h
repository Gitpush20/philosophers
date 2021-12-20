/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:32 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/20 16:42:45 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct s_philo_info
{
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned int	nbr_time_to_eat;
	unsigned int	nb_philo;
	pthread_mutex_t	*death;
}	t_philo_info;

typedef struct philo
{
	pthread_mutex_t	*mutex;
	unsigned int	id;
	unsigned short	is_eating;
	size_t			time;
	t_philo_info	*info;
	pthread_mutex_t	*print;
	unsigned int	nbr_eat;
}	t_philo;

int		get_fork_nb(t_philo *philo, int type);
void	is_finished(t_philo *philos, int i, unsigned int *f);
void	*death_thread(void *ptr);
void	*f(void *ptr);
void	*philo_threads(t_philo *philos);

#endif
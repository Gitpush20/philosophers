/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/21 11:45:49 by mbel-bas         ###   ########.fr       */
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
void	mutex_print(char *str, t_philo *philo);
int		args_int(t_philo_info *info, int ac, char **av);
t_philo	*init_philos(t_philo_info *info);
size_t	get_time(void);
int		ft_atoi(const char *str);

#endif
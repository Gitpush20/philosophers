/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:32 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/19 17:33:58 by mbel-bas         ###   ########.fr       */
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


typedef struct  s_philo_info
{
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned int	nbr_time_to_eat;
	unsigned int	nb_philo;
}	t_philo_info;

typedef struct philo
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*death;
	unsigned int	id;
	unsigned short	is_eating;
	size_t			time;
	t_philo_info	*info;
	pthread_mutex_t	*print;
	unsigned int	nbr_eat;
}	t_philo;

#endif

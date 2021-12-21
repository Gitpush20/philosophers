/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:48:59 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/21 21:21:11 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define R "\x1B[0m"

# define SEM_NAME "SEM_PHILO"
# define SEM_PRINT "SEM_PRINT"

size_t		get_time(void);
int			ft_atoi(const char *str);

typedef struct s_philo_info
{
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned int	nbr_time_to_eat;
	unsigned int	nb_philo;
}	t_philo_info;

typedef struct	s_philo
{
	unsigned long 	time_last_eat;
	t_philo_info	*info;
	unsigned int	is_eating;
	unsigned int	nb_eat;
	unsigned int	id;
	sem_t 			*sem_print;	
}	t_philo;

#endif
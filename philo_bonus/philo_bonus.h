/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:48:59 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/22 11:45:23 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>

# define SEM_NAME "SEM_PHILO"
# define SEM_PRINT "SEM_PRINT"

typedef struct s_philo_info
{
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned int	nbr_time_to_eat;
	unsigned int	nb_philo;
}		t_philo_info;

typedef struct s_philo
{
	unsigned long	time_last_eat;
	t_philo_info	*info;
	unsigned int	is_eating;
	unsigned int	nb_eat;
	unsigned int	id;
	sem_t			*sem_print;	
}		t_philo;

size_t	get_time(void);
int		ft_atoi(const char *str);
int		args_int(t_philo_info *info, int ac, char **av);
void	sem_print(const char *str, t_philo *philo, int type);
void	*sorcate_thread(void *p);
void	synchonizer(t_philo *time, sem_t	*sem_phore, t_philo_info	*info);
void	socrate(int i, t_philo_info	info);
pid_t	process(int i, t_philo_info	info);
void	create_processes(t_philo_info	info);

#endif
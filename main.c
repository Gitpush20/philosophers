/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:11:47 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/20 16:40:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Thread operations include thread creation, 
termination, synchronization (joins,blocking), scheduling,
data management and process interaction;
A thread does not maintain a list of created threads, 
nor does it know the thread that created it*/

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000 + (tv.tv_usec / 1000)));
}

void	mutex_print(char *str, t_philo *philo)
{
	size_t			def;
	static size_t	g_time;

	if (g_time == 0)
		g_time = get_time();
	def = get_time() - g_time;
	pthread_mutex_lock(philo->print);
	printf(str, def, philo->id);
	g_time = get_time();
	pthread_mutex_unlock(philo->print);
}

void	args_int(t_philo_info *info, int ac, char **av)
{
	pthread_mutex_t	*death;

	death = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(death, NULL);
	info->death = death;
	info->nb_philo = atoi(av[1]);
	info->time_to_die = atoi(av[2]) * 1000;
	info->time_to_eat = atoi(av[3]) * 1000;
	info->time_to_sleep = atoi(av[4]) * 1000;
	info->nbr_time_to_eat = -1;
	if (ac == 6)
		info->nbr_time_to_eat = atoi(av[5]);
}

t_philo	*init_philos(t_philo_info *info)
{
	unsigned int		i;
	t_philo				*philos;
	pthread_mutex_t		*mutex;
	pthread_mutex_t		*print;

	print = malloc(sizeof(pthread_mutex_t));
	mutex = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	philos = malloc(sizeof(t_philo) * info->nb_philo);
	pthread_mutex_init(print, NULL);
	if (!mutex || !print || !philos)
		return (NULL);
	i = 0;
	while (i < info->nb_philo)
	{
		philos[i].mutex = mutex;
		philos[i].id = i;
		philos[i].info = info;
		philos[i].print = print;
		philos[i].time = get_time();
		philos[i].nbr_eat = 0;
		philos[i].is_eating = 0;
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_philo_info	info;

	if (!(ac == 6 || ac == 5))
		printf("Error\n");
	args_int(&info, ac, av);
	philos = init_philos(&info);
	philo_threads(philos);
	pthread_mutex_lock(info.death);
	pthread_mutex_lock(info.death);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:11:47 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/19 11:56:27 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
Thread operations include thread creation, termination, synchronization (joins,blocking), scheduling,
data management and process interaction;
A thread does not maintain a list of created threads, nor does it know the thread that created it*/
#include "philo.h"

int		get_fork_nb(t_philo *philo, int type)
{
	int		nb_philo;

	nb_philo = philo->info->nb_philo;
	if (philo->id == 0 && type == -1)
		return (philo->info->nb_philo - 1);
	else{
		return ((philo->id + type) % nb_philo);
	}

}

// size_t	get_time(struct timeval *tv)
// {
// 	gettimeofday(tv, NULL);
// 	return ((tv->tv_sec) * 1000 + (tv->tv_usec / 1000));
//}

size_t	get__time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000 + (tv.tv_usec / 1000)));
}
//1639942275431
void	mutex_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf(str, get__time(), philo->id);
	pthread_mutex_unlock(philo->print);
}

void	*death_thread(void *ptr)
{
	t_philo 		*philos;
	int				nb_philo;
	int				i;
	unsigned int	finished;

	philos = (t_philo *)ptr;
	nb_philo = philos->info->nb_philo;
	i = 0;
	finished = 0;
	while (1)
	{
		//&& philos[i].nbr_eat != philos->info->nbr_time_to_eat
		//
		//printf("%d\n", philos[i].is_eating);
		if ((get__time() - philos[i].time)*1000 > philos->info->time_to_die
			&& philos[i].is_eating == 0)
		{
			mutex_print("%lums %d died\n", &philos[i]);
			pthread_mutex_unlock(philos->death);
			//exit(1);
		}//else{
			//printf("%lu <> %lu\n", (get_time(&tv) - philos[i].time)*1000, philos->info->time_to_die);
		//}
		if (philos[i].nbr_eat != (unsigned int)-1 && 
		philos[i].nbr_eat == philos->info->nbr_time_to_eat)
		{
			philos[i].nbr_eat = (unsigned int)-1; 
			finished++;
		}
		if (finished == philos->info->nb_philo)
		{
			pthread_mutex_unlock(philos->death);
			//exit(0);
		}
		usleep(75);
		i = (i + 1) % nb_philo;
	}
}

void	*f(void *ptr)
{
	t_philo 		*philo;
	int				nb_philo;

	philo = (t_philo *)ptr;
	nb_philo = philo->info->nb_philo;
    while (1)
	{
		pthread_mutex_lock(&(philo->mutex[get_fork_nb(philo, 0)]));
		mutex_print("%lums %d has taken a fork\n", philo);
		//printf("%lums %d has taken a fork %d\n",get__time(), philo->id, get_fork_nb(philo, 0));
		pthread_mutex_lock(&(philo->mutex[get_fork_nb(philo, -1)]));
		mutex_print("%lums %d is eating\n", philo);
		//printf("%lums %d has taken a fork (%d)\n",get__time(), philo->id, get_fork_nb(philo, -1));
		philo->is_eating = 1;
		philo->time = get__time();
		usleep(philo->info->time_to_eat);
		philo->is_eating = 0;
		philo->nbr_eat++;
		pthread_mutex_unlock(&(philo->mutex[get_fork_nb(philo, -1)]));
		pthread_mutex_unlock(&(philo->mutex[get_fork_nb(philo, 0)]));
		if (philo->nbr_eat == philo->info->nbr_time_to_eat)
			return (NULL);
		mutex_print("%lums %d is sleeping\n", philo);
		usleep(philo->info->time_to_sleep);
		mutex_print("%lums %d is thinking\n", philo);
	}
	return (NULL);
}

void	args_int(t_philo_info *info,int ac, char **av)
{
	info->nb_philo = atoi(av[1]);
	info->time_to_die = atoi(av[2]) * 1000;
	info->time_to_eat = atoi(av[3]) * 1000;
	info->time_to_sleep = atoi(av[4]) * 1000;
	info->nbr_time_to_eat = -1;
	if (ac == 6)
		info->nbr_time_to_eat = atoi(av[5]);
}

void	*philo_threads(t_philo *philos)
{
	unsigned int	i;
	pthread_t		*threads;
	pthread_t		death_th;

	threads = malloc(sizeof(pthread_t) * philos->info->nb_philo);
	if (!threads)
		return (NULL);
	i = 0;

	pthread_create(&death_th, NULL, death_thread, philos);
	//pthread_join(&de)
	while (i < philos->info->nb_philo)
	{
		pthread_create(&threads[i], NULL, f, philos + i);
		pthread_detach(threads[i]);
		i = i + 2;
	}
	usleep(50);
	i = 1;
	while (i < philos->info->nb_philo)
	{
		pthread_create(&threads[i], NULL, f, philos + i);
        pthread_detach(threads[i]);
		i = i + 2;
	}
	return (threads);
}

int main(int ac, char **av)
{
	t_philo			*philos;
	unsigned int	i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	death;
	pthread_mutex_t	print;
	t_philo_info 	info;

	if (!(ac == 6 || ac == 5))
		return (1);
	args_int(&info,ac, av);
	mutex = malloc(sizeof(pthread_mutex_t) * info.nb_philo);
	philos = malloc(sizeof(t_philo) * info.nb_philo);
	i = 0;
    pthread_mutex_init(&death, NULL);
    pthread_mutex_init(&print, NULL);
	while (i < info.nb_philo)
	{
		philos[i].mutex = mutex;
		philos[i].id = i;
		philos[i].info = &info;
        philos[i].death = &death;
        philos[i].print = &print;
		philos[i].time = get__time();
		philos[i].nbr_eat = 0;
		philos[i].is_eating = 0;
        pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	philo_threads(philos);
    pthread_mutex_lock(&death);
    if (pthread_mutex_lock(&death))
	   return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/20 20:49:24 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork_nb(t_philo *philo, int type)
{
	int	nb_philo;

	nb_philo = philo->info->nb_philo;
	if (philo->id == 0 && type == -1)
		return (philo->info->nb_philo - 1);
	else
	{
		return ((philo->id + type) % nb_philo);
	}
}

void	is_finished(t_philo *philos, int i, unsigned int *f)
{
	if (philos[i].nbr_eat != (unsigned int)-1
		&& philos[i].nbr_eat == philos->info->nbr_time_to_eat)
	{
		philos[i].nbr_eat = (unsigned int)-1;
		(*f)++;
	}
	if (*f == philos->info->nb_philo)
		pthread_mutex_unlock(philos->info->death);
}

void	*death_thread(void *ptr)
{
	t_philo			*philos;
	int				nb_philo;
	int				i;
	unsigned int	finished;

	philos = (t_philo *)ptr;
	nb_philo = philos->info->nb_philo;
	i = 0;
	finished = 0;
	while (1)
	{
		if ((get_time() - philos[i].time) * 1000 > philos->info->time_to_die
			&& philos[i].is_eating == 0)
		{
			mutex_print("%lu ms %d died\n", &philos[i]);
			pthread_mutex_unlock(philos->info->death);
		}
		is_finished(philos, i, &finished);
		usleep(50);
		i = (i + 1) % nb_philo;
	}
}

void	*f(void *ptr)
{
	t_philo	*philo;
	int		nb_philo;

	philo = (t_philo *)ptr;
	nb_philo = philo->info->nb_philo;
	while (1)
	{
		pthread_mutex_lock(&(philo->mutex[get_fork_nb(philo, 0)]));
		mutex_print("%lu ms %d has taken a fork\n", philo);
		pthread_mutex_lock(&(philo->mutex[get_fork_nb(philo, -1)]));
		mutex_print("%lu ms %d is eating\n", philo);
		philo->is_eating = 1;
		philo->time = get_time();
		usleep(philo->info->time_to_eat);
		philo->is_eating = 0;
		philo->nbr_eat++;
		pthread_mutex_unlock(&(philo->mutex[get_fork_nb(philo, -1)]));
		pthread_mutex_unlock(&(philo->mutex[get_fork_nb(philo, 0)]));
		if (philo->nbr_eat == philo->info->nbr_time_to_eat)
			return (NULL);
		mutex_print("%lu ms %d is sleeping\n", philo);
		usleep(philo->info->time_to_sleep);
		mutex_print("%lu ms %d is thinking\n", philo);
	}
	return (NULL);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philantropist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:32:25 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/22 12:38:07 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	args_int(t_philo_info *info, int ac, char **av)
{
	if ((ac != 5 && ac != 6) || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (-1);
	info->nb_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]) * 1000;
	info->time_to_eat = ft_atoi(av[3]) * 1000;
	info->time_to_sleep = ft_atoi(av[4]) * 1000;
	info->nbr_time_to_eat = -1;
	if (ac == 6)
		info->nbr_time_to_eat = ft_atoi(av[5]);
	return (1);
}

void	sem_print(const char *str, t_philo *philo, int type)
{
	sem_wait(philo->sem_print);
	printf(str, get_time(), philo->id);
	if (type == 0)
		sem_post(philo->sem_print);
}

void	*sorcate_thread(void *p)
{
	t_philo	*t;

	t = (t_philo *)p;
	while (1)
	{
		if (get_time() - t->time_last_eat > t->info->time_to_die / 1000
			&& !t->is_eating)
		{
			sem_print("%lums %d died\n", t, 1);
			exit(0);
		}
		if (t->nb_eat >= t->info->nbr_time_to_eat)
			kill(getpid(), SIGINT);
		usleep(100);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:48:54 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/22 12:40:03 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	synchonizer(t_philo *time, sem_t	*sem_phore, t_philo_info	*info)
{
	while (1)
	{
		sem_wait(sem_phore);
		sem_print("%lums %d has taken a fork\n", time, 0);
		sem_wait(sem_phore);
		sem_print("%lums %d is eating\n", time, 0);
		time->is_eating = 1;
		time->time_last_eat = get_time();
		usleep(info->time_to_eat);
		time->is_eating = 0;
		time->nb_eat++;
		sem_post(sem_phore);
		sem_post(sem_phore);
		if (time->nb_eat < info->nbr_time_to_eat)
		{
			sem_print("%lums %d is sleeping\n", time, 0);
			usleep(info->time_to_sleep);
			sem_print("%lums %d is thinking\n", time, 0);
		}
		else
			sleep(10);
	}
	sem_close(sem_phore);
}

void	socrate(int i, t_philo_info	info)
{
	sem_t			*sem_phore;
	pthread_t		thread;
	t_philo			*time;

	time = malloc(sizeof(t_philo));
	time->time_last_eat = get_time();
	time->info = &info;
	time->id = i;
	time->is_eating = 0;
	time->nb_eat = 0;
	pthread_create(&thread, NULL, sorcate_thread, time);
	pthread_detach(thread);
	sem_phore = sem_open(SEM_NAME, 0);
	time->sem_print = sem_open(SEM_PRINT, 0);
	if (sem_phore == SEM_FAILED)
		exit(1);
	synchonizer(time, sem_phore, &info);
}

pid_t	process(int i, t_philo_info	info)
{
	pid_t	k;

	k = fork();
	if (!k)
	{
		socrate(i, info);
		usleep(100);
		exit(0);
	}
	return (k);
}

void	create_processes(t_philo_info	info)
{
	unsigned int	i;
	pid_t			*pids;
	pid_t			p;
	int				status;

	i = -1;
	pids = malloc(sizeof(pid_t) * info.nb_philo);
	while (++i < info.nb_philo)
		pids[i] = process(i, info);
	p = waitpid(0, &status, WUNTRACED | WCONTINUED);
	while (p != -1)
	{
		if (WIFEXITED(status))
			break ;
		else if (WIFSTOPPED(status))
			kill(p, 9);
		p = waitpid(0, &status, WUNTRACED | WCONTINUED);
	}
	i = -1;
	while (++i < info.nb_philo)
		if (pids[i] != p)
			kill(pids[i], 9);
	free(pids);
}

int	main(int ac, char **av)
{
	t_philo_info	info;
	int				err;

	err = args_int(&info, ac, av);
	if (err == -1)
	{
		printf("Error : NUMBER OF ARGUMENTS IS NOT CORRECT");
		return (1);
	}
	sem_unlink(SEM_NAME);
	sem_unlink(SEM_PRINT);
	sem_open(SEM_NAME, O_CREAT, 0666, info.nb_philo);
	sem_open(SEM_PRINT, O_CREAT, 0666, 1);
	create_processes(info);
	sem_unlink(SEM_NAME);
	sem_unlink(SEM_NAME);
	return (1);
}

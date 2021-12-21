/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:48:54 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/12/21 22:08:34 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char colors[7][6] = {
	"\x1B[31m",
	"\x1B[32m",
	"\x1B[33m",
	"\x1B[34m",
	"\x1B[35m",
	"\x1B[36m",
	"\x1B[37m"
};

int	args_int(t_philo_info *info, int ac, char **av)
{
	if ((ac != 5 && ac != 6) || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60
		|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
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
		if (get_time() - t->time_last_eat > t->info->time_to_die / 1000 && !t->is_eating)
		{
			sem_print("%lums %d died\n", t, 1);
			//printf("%lu %d die\n", get_time(), t->id);
			exit(0);
		}
		if (t->nb_eat >= t->info->nbr_time_to_eat)
		{
			kill(getpid(), SIGINT);
		}
		usleep(100);
	}
}

void	socrate(int i, t_philo_info	info)
{
	sem_t 			*sem_phore;
	pthread_t		thread;
	t_philo			*time;
	
	//printf("philo pid = %d end\n", getpid());
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
	if(sem_phore == SEM_FAILED){
        printf("sem_open");
        exit(1);
    }
	while (1)
	{
		sem_wait(sem_phore);
		sem_print("%lums %d has taken a fork\n", time, 0);
		sem_wait(sem_phore);
		sem_print("%lums %d is eating\n", time, 0);
		time->is_eating = 1;
		time->time_last_eat = get_time();
		usleep(info.time_to_eat);
		time->is_eating = 0;
		time->nb_eat++;
		sem_post(sem_phore);
		sem_post(sem_phore);
		if (time->nb_eat < info.nbr_time_to_eat)
		{
			sem_print("%lums %d is sleeping\n", time, 0);
			usleep(info.time_to_sleep);
			sem_print("%lums %d is thinking\n", time, 0);
		}else
			sleep(10);
	}
	sem_close(sem_phore);
}


pid_t	process(int i, t_philo_info	info)
{
	pid_t k;
	
	k = fork();
	if (!k)
	{
		socrate(i, info);
		exit(0);
	}
	return (k);
}

void    create_processes(t_philo_info	info)
{
	unsigned int	i;
	pid_t			*pids;
	pid_t			p;
	int				status;

	i = 0;
	pids = malloc(sizeof(pid_t) * info.nb_philo);
	while (i < info.nb_philo)
	{
		pids[i] = process(i, info);
		i++;
	}
	while ((p = waitpid(0, &status, WUNTRACED | WCONTINUED)) != -1)
	{
		if (WIFEXITED(status))
			break;
		else if (WIFSTOPPED(status))
			kill(p, 9);
	}
	i = 0;
	while (i < info.nb_philo)
	{
		if (pids[i] != p)
			kill(pids[i], 9);
		i++;
	}
	free(pids);
}

int main(int ac, char **av)
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
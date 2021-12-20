#include "philo.h"

size_t	get__time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 10000 + (tv.tv_usec / 100)));
}

int main()
{
	printf("%lu", get__time());
}
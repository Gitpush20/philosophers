/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:02:35 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/10 12:03:25 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	signe(size_t n)
{
	if (n == 1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	size_t				sign;
	int					t;
	unsigned long long	loo;

	i = 0;
	sign = 1;
	loo = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	t = i;
	while (str[i] <= '9' && str[i] >= '0')
		loo = loo * 10 + str[i++] - 48;
	if (i - t > 19 || loo > 9223372036854775807)
		return (signe(t));
	return ((int)(loo * sign));
}

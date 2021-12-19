/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:56:18 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/11 15:33:05 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(unsigned int nb)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_set(char *a, unsigned int nb, size_t len, size_t n)
{
	size_t	k;
	size_t	s;

	while (len > 0)
	{
		s = len - 1;
		k = 1;
		while (s > 0)
		{
			k = k * 10;
			s--;
		}
		a[n] = ((nb / k) % 10) + '0';
		n++;
		len--;
	}
}

char	*ft_setitoa(unsigned int nb, size_t flag)
{
	char	*a;
	size_t	len;
	size_t	n;

	len = ft_len(nb);
	n = 0;
	if (flag)
	{
		a = malloc(len + 2);
		if (!a)
			return (NULL);
		a[n] = '-';
		n++;
	}
	else
		a = malloc(len + 1);
	ft_set(a, nb, len, n);
	if (flag)
		a[len + 1] = '\0';
	else
		a[len] = '\0';
	return (a);
}

char	*ft_itoa(int n)
{
	size_t			flag;
	unsigned int	nb;
	char			*a;

	flag = 0;
	nb = n;
	if (n == 0)
	{
		a = malloc(2);
		if (!a)
			return (NULL);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	if (n < 0)
	{
		nb = n * (-1);
		flag = 1;
	}
	a = ft_setitoa(nb, flag);
	return (a);
}

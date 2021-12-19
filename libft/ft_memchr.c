/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:17:36 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/15 22:33:20 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
		{
			return (d + i);
		}
		i++;
	}
	return (NULL);
}

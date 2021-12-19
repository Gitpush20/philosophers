/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:33:11 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/09 19:48:20 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)src;
	s2 = (char *)dst;
	if (!s1 && !s2)
		return (NULL);
	if (s2 > s1)
	{
		while (n-- > 0)
		{
			s2[n] = s1[n];
		}
	}
	else
		ft_memcpy(s2, s1, n);
	return (s2);
}

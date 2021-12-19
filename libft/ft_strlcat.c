/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:10:52 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/15 22:44:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	i = 0;
	if (!dst && len == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	j = lend;
	if (len == 0 || len <= lend)
	{
		return (len + lens);
	}
	while (src[i] && i < len - lend - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (lens + lend);
}

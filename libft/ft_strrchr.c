/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:42:12 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/15 22:34:31 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	d;
	int		len;

	d = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == d)
		{
			return ((char *)str + len);
		}
		len--;
	}
	return (0);
}

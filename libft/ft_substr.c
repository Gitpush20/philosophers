/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:14:24 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/12 10:17:24 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr( const char *s, size_t start, size_t len )
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		str = malloc(1);
	else if (ft_strlen(s) - start <= len)
		str = malloc(ft_strlen(s) - start + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (i < len && s[i])
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

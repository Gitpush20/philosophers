/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:20:19 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/11 09:27:28 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	s = (char *)haystack;
	if (!ft_strlen(needle))
		return (s);
	while (s[i] && i < len)
	{
		if (s[i] == needle[0])
		{
			j = 0;
			while (s[i + j] == needle[j] && i + j < len && needle[j])
				j++;
			if (j == ft_strlen(needle))
				return (s + i);
		}
		i++;
	}
	return (NULL);
}

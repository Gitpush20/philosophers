/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:56:18 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/11 11:23:35 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **ar, size_t k)
{
	size_t	i;

	i = 0;
	while (i <= k)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static void	ft_size(char **ar, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
		{
			ar[k] = ft_substr(s, j, i - j);
			if (!ar[k])
				ft_free(ar, k);
			k++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_len(s, c);
	ar = malloc(sizeof(char *) * (j + 1));
	if (!ar)
		return (NULL);
	ft_size(ar, s, c);
	ar[j] = NULL;
	return (ar);
}

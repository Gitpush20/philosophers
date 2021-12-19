/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:41:10 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/09 20:10:05 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

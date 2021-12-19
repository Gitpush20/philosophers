/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:37:49 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/09 11:06:00 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		counter;

	tmp = lst;
	counter = 0;
	while (tmp != NULL)
	{
		counter += 1;
		tmp = tmp->next;
	}
	return (counter);
}

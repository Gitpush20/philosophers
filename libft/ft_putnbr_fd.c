/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:51 by mbel-bas          #+#    #+#             */
/*   Updated: 2021/11/06 15:26:52 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_fd(int n, int fd)
{
	if (n > 9)
	{
		ft_print_fd((n / 10), fd);
		ft_putchar_fd ((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd (n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	nb;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (fd < 0)
	{
		return ;
	}
	nb = n;
	if (n < 0)
	{
		nb = n * (-1);
		write(fd, "-", 1);
	}
	ft_print_fd(nb, fd);
}

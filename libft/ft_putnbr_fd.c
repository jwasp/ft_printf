/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:55 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/13 19:03:48 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	minus(int n, int fd)
{
	ft_putchar_fd('-', fd);
	n = -n;
	return (n);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	num[10];
	int	min;
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		n = minus(n, fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n > 0)
	{
		min = n % 10;
		num[i++] = min;
		n /= 10;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_fd(num[i] + '0', fd);
	}
}

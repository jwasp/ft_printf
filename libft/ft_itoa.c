/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:02:25 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/12 18:50:30 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_int(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = len_int(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		len = len + 1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[len--] = '\0';
	while (n)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

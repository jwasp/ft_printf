/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:14:40 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:00:12 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	len_int(unsigned int num)
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

char		*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*res;

	len = len_int(n);
	if (n == 0)
		return (ft_strdup("0"));
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len--] = '\0';
	while (n)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

int			ft_print_u(unsigned int i, t_flags flags)
{
	char	*str;
	int		count;

	count = 0;
	if (i == 0 && flags.accuracy == 0)
		return (count += ft_print_space(flags.width, 0));
	str = ft_itoa_u(i);
	if (flags.zero == 1 && flags.accuracy <= -1 && flags.width)
	{
		count += ft_print_zero(flags.width, ft_strlen(str));
		return (count += write(1, str, (ft_strlen(str))));
	}
	count += ft_print_number_with_flags(str, flags);
	free(str);
	return (count);
}

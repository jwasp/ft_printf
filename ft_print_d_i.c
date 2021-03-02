/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:27:28 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 18:58:53 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_space(int width, int len)
{
	int		spaces_len;

	spaces_len = ((width > len) ? width - len : 0);
	while (width > len)
	{
		write(1, " ", 1);
		width--;
	}
	return (spaces_len);
}

int		ft_print_zero(int width, int len)
{
	int		zero_len;

	zero_len = ((width > len) ? width - len : 0);
	while (width > len)
	{
		write(1, "0", 1);
		width--;
	}
	return (zero_len);
}

int		check_accuracy(t_flags flags, size_t len)
{
	if (flags.accuracy < 0 || (size_t)flags.accuracy < len)
		flags.accuracy = 0;
	else
		flags.accuracy = flags.accuracy - len;
	return (flags.accuracy);
}

int		ft_print_number_with_flags(char *str, t_flags flags)
{
	int		count;
	int		neg;

	count = 0;
	neg = (str[0] == '-');
	str += neg;
	if (flags.minus == 1)
	{
		count += write(1, "-", neg);
		count += ft_print_zero(flags.accuracy, ft_strlen(str));
		count += write(1, str, ft_strlen(str));
		count += ft_print_space(flags.width, count);
	}
	else
	{
		flags.width -= neg;
		flags.accuracy = check_accuracy(flags, ft_strlen(str));
		count += ft_print_space(flags.width, ft_strlen(str) + flags.accuracy);
		count += write(1, "-", neg);
		count += ft_print_zero(flags.accuracy, 0);
		count += write(1, str, ft_strlen(str));
	}
	return (count);
}

int		ft_print_int(int i, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	if (i == 0 && flags.accuracy == 0)
		return (count += ft_print_space(flags.width, 0));
	str = ft_itoa(i);
	if (flags.zero == 1 && flags.accuracy <= -1 && flags.width > 0)
	{
		if (str[0] == '-')
		{
			count += write(1, "-", 1);
			str++;
			flags.width--;
		}
		count += ft_print_zero(flags.width, ft_strlen(str));
		return (count += write(1, str, (ft_strlen(str))));
	}
	count += ft_print_number_with_flags(str, flags);
	free(str);
	return (count);
}

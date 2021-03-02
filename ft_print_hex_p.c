/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:32:10 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 18:59:39 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_pointer_with_flags(char *str, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
	{
		count += write(1, "0x", 2);
		count += ft_print_zero(flags.accuracy, ft_strlen(str));
		count += write(1, str, ft_strlen(str));
		count += ft_print_space(flags.width, count);
	}
	else
	{
		flags.width -= 2;
		flags.accuracy = check_accuracy(flags, ft_strlen(str));
		count += ft_print_space(flags.width, ft_strlen(str) + flags.accuracy);
		count += write(1, "0x", 2);
		count += ft_print_zero(flags.accuracy, 0);
		count += write(1, str, ft_strlen(str));
	}
	return (count);
}

char	*ft_itoa_x(unsigned long num, int reg)
{
	char			*res;
	int				i;
	int				digit;
	unsigned long	n_buf;

	i = 1;
	n_buf = num;
	while (n_buf /= 16)
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	reg = 'a' - reg * 32;
	while (i > 0)
	{
		i--;
		digit = num % 16;
		if (digit > 9)
			res[i] = reg + digit - 10;
		else
			res[i] = digit + '0';
		num /= 16;
	}
	return (res);
}

int		ft_print_hex(unsigned int i, int reg, t_flags flags)
{
	char	*str;
	int		count;

	count = 0;
	if (i == 0 && flags.accuracy == 0)
		return (count += ft_print_space(flags.width, 0));
	str = ft_itoa_x(i, reg);
	if (flags.zero == 1 && flags.accuracy <= -1 && flags.width)
	{
		count += ft_print_zero(flags.width, ft_strlen(str));
		return (count += write(1, str, (ft_strlen(str))));
	}
	count += ft_print_number_with_flags(str, flags);
	free(str);
	return (count);
}

int		ft_print_pointer(unsigned long i, t_flags flags)
{
	char	*str;
	int		count;

	str = NULL;
	count = 0;
	if (i == 0 && flags.accuracy == 0)
	{
		count += ft_print_space(flags.width - 2, 0);
		count += write(1, "0x", 2);
	}
	str = ft_itoa_x((unsigned long)i, 0);
	if (flags.zero == 1 && flags.accuracy <= -1 && flags.width)
	{
		count += ft_print_zero(flags.width, ft_strlen(str));
		return (count += write(1, str, (ft_strlen(str))));
	}
	count += ft_print_pointer_with_flags(str, flags);
	free(str);
	return (count);
}

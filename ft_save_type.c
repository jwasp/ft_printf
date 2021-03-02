/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:14:28 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:24:59 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_the_type(int c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X'
		|| c == 'u' || c == 'p' || c == 's' || c == 'c' || c == '%')
		return (c);
	return (0);
}

int		ft_print_type(char c, va_list args, t_flags flags)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int), flags);
	if (c == '%')
		count = ft_print_char('%', flags);
	if (c == 's')
		count = ft_print_string(va_arg(args, char *), flags);
	if (c == 'p')
		count = ft_print_pointer(va_arg(args, uintptr_t), flags);
	if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(args, int), flags);
	if (c == 'u')
		count = ft_print_u(va_arg(args, unsigned int), flags);
	if (c == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0, flags);
	if (c == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1, flags);
	return (count);
}

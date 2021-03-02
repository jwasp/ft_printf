/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:16:19 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 18:58:09 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c, t_flags flags)
{
	int	count;

	count = (flags.width ? flags.width : 1);
	if (flags.minus)
		write(1, &c, 1);
	ft_print_space(flags.width, 1);
	if (!flags.minus)
		write(1, &c, 1);
	return (count);
}

int		ft_print_string(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.accuracy == -1)
		flags.accuracy = ft_strlen(str);
	if (flags.accuracy > 0 && (size_t)flags.accuracy > ft_strlen(str))
		flags.accuracy = ft_strlen(str);
	if (flags.minus == 1)
		count += write(1, str, flags.accuracy);
	if (flags.accuracy >= 0)
		count += ft_print_space(flags.width, flags.accuracy);
	if (flags.accuracy < 0)
		count += ft_print_space(flags.width, ft_strlen(str));
	if (flags.minus == 0)
		count += write(1, str, flags.accuracy);
	return (count);
}

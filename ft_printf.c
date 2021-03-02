/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:46:21 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:26:32 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse(char **input, va_list args)
{
	t_flags flags;
	int		state;

	flags = new_flags();
	state = 1;
	if (!*input)
		return (-1);
	if (**input == '0' || **input == '-')
		state = ft_save_flags(input, &flags);
	if ((ft_isdigit(**input) || **input == '*') && (state == 2 || state == 1))
		state = save_width(input, &flags, args);
	if (**input == '.' && (state == 2 || state == 1 || state == 3))
		state = save_acc(input, &flags, args);
	if (ft_the_type(**input) && (state == 2
		|| state == 1 || state == 3 || state == 4 || state == 5))
	{
		flags.type = **input;
		(*input)++;
		return (ft_print_type(flags.type, args, flags));
	}
	return (-1);
}

int		ft_printf(const char *input, ...)
{
	int		count_of_print;
	va_list	args;
	int		status;

	count_of_print = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			status = ft_parse((char **)&input, args);
			if (status == -1)
				return (-1);
			count_of_print += status;
		}
		else if (*input != '%')
		{
			count_of_print += write(1, input, 1);
			input++;
		}
	}
	va_end(args);
	return (count_of_print);
}

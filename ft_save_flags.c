/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:21:43 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:01:14 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	new_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.accuracy = -1;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int		save_width(char **input, t_flags *flags, va_list args)
{
	int		state;

	state = 5;
	while (**input == '*' || ft_isdigit(**input))
	{
		if (ft_isdigit(**input))
			flags->width = ft_atoi(*input);
		while (ft_isdigit(**input))
			(*input)++;
		if (**input == '*')
		{
			flags->width = va_arg(args, int);
			(*input)++;
		}
		state = 3;
	}
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
		flags->zero = 0;
		state = 3;
	}
	return (state);
}

int		save_acc(char **input, t_flags *flags, va_list args)
{
	int		state;

	state = 5;
	(*input)++;
	if (**input != '*' && !ft_isdigit(**input))
		flags->accuracy = 0;
	while (**input == '*' || ft_isdigit(**input))
	{
		if (ft_isdigit(**input))
			flags->accuracy = ft_atoi(*input);
		while (ft_isdigit(**input))
			(*input)++;
		if (**input == '*')
		{
			flags->accuracy = va_arg(args, int);
			(*input)++;
		}
		state = 4;
	}
	if (flags->accuracy < 0)
	{
		flags->accuracy = -1;
		state = 4;
	}
	return (state);
}

int		ft_save_flags(char **input, t_flags *flags)
{
	int		state;

	state = 5;
	while (**input == '0' || **input == '-')
	{
		if (**input == '-')
			flags->minus = 1;
		(*input)++;
		state = 2;
	}
	flags->zero = ((flags->minus == 1) ? 0 : 1);
	return (state);
}

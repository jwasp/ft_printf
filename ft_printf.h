/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:37:56 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:25:45 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_flags.h"
# include "libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_parse(char **input, va_list args);
int		ft_save_flags(char **input, t_flags *flags);
int		save_acc(char **input, t_flags *flags, va_list args);
int		save_width(char **input, t_flags *flags, va_list args);
int		ft_the_type(int c);
int		ft_print_type(char c, va_list args, t_flags flags);
int		ft_print_space(int width, int len);
int		ft_print_zero(int width, int len);
int		check_accuracy(t_flags flags, size_t len);
int		ft_print_number_with_flags(char *str, t_flags flags);
int		ft_print_int(int i, t_flags flags);
int		ft_print_u(unsigned int i, t_flags flags);
char	*ft_itoa_u(unsigned int n);
int		ft_print_pointer(unsigned long i, t_flags flags);
int		ft_print_hex(unsigned int i, int reg, t_flags flags);
char	*ft_itoa_x(unsigned long num, int reg);
int		ft_print_pointer_with_flags(char *str, t_flags flags);
int		ft_print_char(char c, t_flags flags);
int		ft_print_string(char *str, t_flags flags);

#endif

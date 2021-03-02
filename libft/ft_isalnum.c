/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:56:43 by jwasp             #+#    #+#             */
/*   Updated: 2020/10/31 22:24:08 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	return (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ||
	(ch >= 48 && ch <= 57) ? 1 : 0));
}
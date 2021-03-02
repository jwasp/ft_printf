/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:36 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/02 18:45:56 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		((unsigned char*)dst)[i] = (unsigned char)c;
	}
	return ((unsigned char*)dst);
}

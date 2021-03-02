/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:22:05 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/13 19:21:27 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	int		b;
	size_t	i;

	b = 0;
	i = 0;
	while (i < num)
	{
		b = (((unsigned char *)memptr1)[i] - ((unsigned char *)memptr2)[i]);
		if (b != 0)
			return (b);
		i++;
	}
	return (b);
}

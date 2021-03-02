/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:28 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/13 19:08:07 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	i;

	i = 0;
	if (((unsigned char*)src) > ((unsigned char*)dest))
	{
		while (i < num)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	if (((unsigned char*)src) < ((unsigned char*)dest))
		while (num--)
		{
			((unsigned char*)dest)[num] = ((unsigned char*)src)[num];
		}
	return (dest);
}

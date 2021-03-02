/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:23:05 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:42:22 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == source)
		return (dest);
	while (i < len)
	{
		((unsigned char*)dest)[i] = ((const unsigned char*)source)[i];
		i++;
	}
	return (dest);
}

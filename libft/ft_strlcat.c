/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:30:28 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:44:07 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
	{
		len++;
	}
	while (len + 1 + i < size && src[i])
	{
		dst[len + i] = (src)[i];
		i++;
	}
	if (len < size)
	{
		dst[len + i] = '\0';
	}
	len += ft_strlen(src);
	return (len);
}

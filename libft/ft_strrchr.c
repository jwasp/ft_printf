/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:20:49 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:44:44 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = ft_strlen(str);
	i += 1;
	while (i--)
	{
		if ((unsigned char)str[i] == (unsigned char)ch)
		{
			return ((char*)str + i);
		}
	}
	return (NULL);
}

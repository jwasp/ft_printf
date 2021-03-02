/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:41 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:43:49 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(string));
	len++;
	while (i < len)
	{
		if (string[i] == symbol)
			return ((char *)string + i);
		i++;
	}
	return (NULL);
}

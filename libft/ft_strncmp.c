/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:50:08 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/13 21:48:56 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		b;

	b = 0;
	i = 0;
	if (str1[i] == '\0' && *str2)
		return (-1);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		b = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (b != 0)
		{
			if (b < 0)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (b);
}

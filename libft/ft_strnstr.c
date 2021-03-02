/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:18:30 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:44:32 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	count;

	i = -1;
	if (!*little || little == big)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (++i < len && big[i] != '\0')
	{
		k = 0;
		count = 0;
		while (little[k] == big[i + count]
		&& little[k] != '\0' && i + count < len)
		{
			count++;
			k++;
		}
		if (k == ft_strlen(little))
			return ((char*)big + i);
	}
	return (0);
}

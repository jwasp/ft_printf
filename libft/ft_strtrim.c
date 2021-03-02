/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:52:29 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/13 19:19:34 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		int	same(char c, char const *b)
{
	size_t	i;

	i = 0;
	while (b[i] != '\0')
	{
		if (c == b[i++])
			return (0);
	}
	return (1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (same(s1[i], set) == 0)
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (same(s1[len - 1], set) == 0)
		len--;
	result = ft_substr(s1, i, len - i);
	return (result);
}

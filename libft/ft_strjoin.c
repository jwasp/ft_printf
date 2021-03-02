/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:10:31 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/06 19:28:47 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sumstr;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sumstr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!sumstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		sumstr[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		sumstr[i] = *((char *)s2++);
		i++;
	}
	sumstr[i] = '\0';
	return (sumstr);
}

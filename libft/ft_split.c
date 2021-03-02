/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:58:40 by jwasp             #+#    #+#             */
/*   Updated: 2020/11/18 00:39:07 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	countword(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static	size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while ((*s) && (*s != c))
	{
		len++;
		s++;
	}
	return (len);
}

static	char	**ft_free(char **words)
{
	size_t	i;

	i = 0;
	while (words)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

static	char	**ft_filled(char const *s, char c, char **mas, size_t words)
{
	size_t	k;
	size_t	i;
	size_t	len;

	k = -1;
	while (++k < words)
	{
		while (*s == c)
			s++;
		len = len_word(s, c);
		if (!(mas[k] = (char *)malloc(sizeof(char) * (len + 1))))
		{
			return (ft_free(mas));
		}
		i = 0;
		while (i < len)
		{
			mas[k][i] = *s;
			i++;
			s++;
		}
		mas[k][i] = '\0';
	}
	mas[k] = (NULL);
	return (mas);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = countword(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	res = ft_filled(s, c, res, words);
	return (res);
}

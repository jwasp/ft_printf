/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:46:00 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 19:08:10 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(const char *str);
void	*ft_memset(void *dst, int c, size_t n);
void	*ft_memcpy(void *dest, const void *source, size_t len);
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
char	*ft_strchr(const char *string, int symbol);
void	*ft_memmove(void *destptr, const void *srcptr, size_t num);
char	*ft_strrchr(const char *str, int ch);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_isalpha(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t num, size_t size);
char	**ft_split(char const *s, char c);

#endif

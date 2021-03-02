# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 20:51:35 by jwasp             #+#    #+#              #
#    Updated: 2020/11/17 18:23:23 by jwasp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GC = gcc
FLAGS = -Wextra -Werror -Wall -c
FUNCS = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putchar_fd.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_split.c
OBJS = $(FUNCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(GC) $(FLAGS) $(FUNCS) libft.h
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY:	clean	fclean	all	re

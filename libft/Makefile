# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:32:23 by rdeanne           #+#    #+#              #
#    Updated: 2021/10/20 15:32:25 by rdeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_calloc.c     ft_isascii.c    ft_isspace.c    ft_memcmp.c     ft_memset.c     ft_putnbr_fd.c  ft_strchr.c     \
			ft_strjoin.c    ft_strlen.c     ft_strnstr.c    ft_substr.c		ft_atoi.c       ft_isalnum.c    ft_toupper.c	\
			ft_isdigit.c    ft_itoa.c       ft_memcpy.c     ft_putchar_fd.c ft_putstr_fd.c	ft_strdup.c     ft_strlcat.c    \
			ft_strmapi.c    ft_strrchr.c    ft_tolower.c	ft_bzero.c      ft_isalpha.c    ft_isprint.c    ft_memchr.c     \
			ft_memmove.c    ft_putendl_fd.c ft_split.c      ft_striteri.c   ft_strlcpy.c    ft_strncmp.c    ft_strtrim.c    \

HEADER	=	libft.h
OBJ		=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

NAME	=	libft.a
CC		=	gcc

HEADER	=	../includes/libft.h
INCLUDE	=	../includes

CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE)

SRCS	=	ft_atoi.c		ft_isdigit.c	ft_putchar_fd.c	ft_putnbr_fd.c \
			ft_putstr_fd.c	ft_strchr.c		ft_strjoin.c	ft_strlen.c \
			ft_strrchr.c	ft_tolower.c	ft_tolower.c	ft_strncmp.c \
			ft_putendl_fd.c	ft_inset.c

OBJS	=	${SRCS:.c=.o}

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
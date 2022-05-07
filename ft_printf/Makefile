NAME	=	libftprintf.a

SRCS	=	main.c ft_printf.c src/ft_putnbr_fd.c src/ft_putstr_fd.c \
			src/ft_putchar_fd.c src/ft_putptr_fd.c src/ft_strlen.c \
			src/ft_tolower.c src/ft_toupper.c src/ft_putbase16_fd.c \
			src/ft_printf_utils.c src/ft_atoi.c src/ft_isdigit.c \
			src/ft_strrchr.c src/utils.c

HEADER	=	headers
OBJ		=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

.PHONY	:	all clean fclean re

bonus	:	all

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

NAME		=	push_swap 
CHECKER		=	checker
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra

INCLUDES	=	-I includes

#--------------------LIBFT----------------------
LIB_SRCDIR	=	libft/
LIB_SRC		=	ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_strcmp.c ft_strncmp.c \
				ft_isnum.c ft_strlcpy.c ft_isspace.c ft_split.c
LIB_SRCS	=	$(addprefix $(LIB_SRCDIR), $(LIB_SRC))


LIB_NAME	=	libft.a
# HEADER		=	includes/libft.h

LIB_OBJS	=	$(LIB_SRCS:.c=.o)
#-----------------------------------------------
#------------------PUSH_SWAP--------------------

SRC			=	stack_operations_1.c utils1.c push.c swap.c rotate.c stack_operations_3.c \
				rev_rotate.c sort.c stack_operations_2.c short_sort.c utils2.c\
				big_sort.c
SRCDIR		=	srcs/
SRCS		=	push_swap.c
SRCS		+= 	$(addprefix $(SRCDIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)
DEPS		=	includes/push_swap.h includes/utils.h includes/libft.h includes/get_next_line.h

BONUS_SRCS	=	gnl/get_next_line.c gnl/get_next_line_utils.c check/checker.c \
				check/c_push.c check/c_rotate.c check/c_rev_rotate.c check/c_swap.c \
				srcs/utils1.c srcs/utils2.c srcs/stack_operations_2.c srcs/sort.c srcs/stack_operations_1.c srcs/stack_operations_3.c \
				check/cutils.c
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

.PHONY : all clean fclean re bonus

all		:	$(LIB_NAME) $(NAME)
bonus	:	$(CHECKER)

$(CHECKER)	:	$(LIB_NAME) $(NAME) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIB_NAME) -o $(CHECKER)

$(LIB_NAME)	:	$(LIB_OBJS) includes/libft.h
	ar rcs $(LIB_NAME) $?

$(NAME)	:	$(OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME)

%.o		:	%.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	:
	@rm -f $(OBJS) $(LIB_OBJS) $(BONUS_OBJS)

fclean	:	clean
	@$(RM) $(NAME) $(LIB_NAME) $(CHECKER)

re		:	fclean all
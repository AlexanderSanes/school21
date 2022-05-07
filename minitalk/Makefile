SERVER_SRCS	=	server.c
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
SERVER_NAME	=	server

CLIENT_SRCS	=	client.c
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
CLIENT_NAME	=	client

SRCS		=	utils.c
OBJS		=	$(SRCS:.c=.o)

DEPS		=	utils.h

NAME		=	minitalk
RM			=	rm -f
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I.

$(NAME)		:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME)	:	$(OBJS) $(SERVER_OBJS) $(DEPS) 
			$(CC) $(CFLAGS) $(OBJS) $(SERVER_OBJS) -o $@

$(CLIENT_NAME)	:	$(OBJS) $(CLIENT_OBJS) $(DEPS) 
			$(CC) $(CFLAGS) $(OBJS) $(CLIENT_OBJS) -o $@

%.o				:	%.c	$(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all		:	$(NAME)

clean		:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS)

fclean		:	clean
			$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re		:	fclean all

bonus		:	$(NAME)

.PHONY		:	all clean fclean re bonus

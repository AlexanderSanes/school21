NAME	=	philo
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
INCLUDE	=	-I includes

OBJDIR	=	obj
SRCDIR	=	src
HEADERS	=	includes/philo.h

SRC		=	main.c philo.c philo_actions.c init.c
OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	:	all clean fclean re

all			:	$(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)		:	$(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o	:	%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	rm -f $(NAME)

re		: fclean all


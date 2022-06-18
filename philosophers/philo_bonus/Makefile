NAME	=	philo_bonus
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
INCLUDE	=	-I includes

OBJDIR	=	obj
SRCDIR	=	src
HEADERS	=	includes/philo_bonus.h

SRC		=	main_bonus.c philo_bonus.c philo_actions_bonus.c init_bonus.c
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


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2022/04/14 17:57:35 by rdeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	solong

CC			=	gcc

INCLUDE		=	-I includes

LIBFTNAME	=	libft.a

CFLAGS		=	-Werror -Wall -Wextra

MINILIBX	=	-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

SRC			=	main.c 
MAPSRC		=	parse_map.c map_utils.c get_next_line.c error.c 
RENDERSRC	=	hooks.c control_player.c keycode_action.c render.c window_params.c images.c game_over.c

OBJDIR		=	obj
OBJS		=	$(SRC:%.c=$(OBJDIR)/%.o) $(MAPSRC:%.c=$(OBJDIR)/%.o) $(RENDERSRC:%.c=$(OBJDIR)/%.o)

SRCS		=	$(SRC) mapsrc/$(MAPSRC) rendersrc/$(RENDERSRC)

LIBFTPATH	=	libft

DEPS		=	includes/libft.h includes/get_next_line.h includes/so_long.h

.PHONY		:	all clean fclean re

all			:	$(OBJDIR) $(NAME)

$(OBJDIR)	:
	mkdir obj

${NAME}		:	${OBJS}
	make -C ${LIBFTPATH}
	${CC} ${CFLAGS} ${OBJS} ${MINILIBX} ${LIBFTPATH}/${LIBFTNAME} -o ${NAME}

$(OBJDIR)/%.o		:	%.c $(DEPS)
	$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@
$(OBJDIR)/%.o		:	mapsrc/%.c $(DEPS)
	$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@
$(OBJDIR)/%.o		:	rendersrc/%.c $(DEPS)
	$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@

clean	:
	make -C ${LIBFTPATH} clean
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	make -C ${LIBFTPATH} fclean
	rm -f $(NAME)

re		:	fclean all
NAME =		Cub3D

SRCS =		srcs/main.c \
			srcs/init1.c \
			srcs/init2.c \
			srcs/parsing.c \
			srcs/map.c \
			srcs/checks.c \
			srcs/draw.c \
			srcs/raycasting.c \
			srcs/sprites.c \
			srcs/controller.c \
			srcs/movements.c \
			srcs/utils_strings.c \
			srcs/utils_pixels.c \
			srcs/utils_bmp.c \
			srcs/memory.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

FLAGS =		-Wall -Werror -Wextra

INC =		/usr/local/include

LIB =		/usr/local/lib

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLX				= mlxopengl

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) -L $(MLX) $(LXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

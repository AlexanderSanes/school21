/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:37:13 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/15 17:36:06 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"

// # include <stdio.h>

# include "get_next_line.h"

# define TILE_WIDTH 80

# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define EXIT 'E'
# define PLAYER 'P'

# define COLLECTIBLE_IMG "xmp_files/dot.xpm"
# define WALL_IMG "xmp_files/wall.xpm"
# define EMPTY_IMG "xmp_files/black.xpm"
# define EXIT_IMG "xmp_files/exit.xpm"
# define PLAYER_R_IMG "xmp_files/pacman_right.xpm"
# define PLAYER_L_IMG "xmp_files/pacman_left.xpm"
# define PLAYER_U_IMG "xmp_files/pacman_up.xpm"
# define PLAYER_D_IMG "xmp_files/pacman_down.xpm"

# define GAME_WON "You won!"

# define COLOR 0x00FE65

typedef struct s_game_map
{
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
	int		game_score;
	int		max_score;
	char	**data;
	int		game_over;
	int		steps;
	void	*wall;
	void	*exit;
	void	*player;
	void	*bg;
	void	*collectible;
	char	player_direction;
}	t_game_map;

typedef struct s_window_v {
	void	*mlx;
	void	*win;
}	t_window;

int			check_map_name(char *map_name);
void		init_map(t_game_map *map);
int			check_map(t_game_map map);
t_game_map	*parse_map(char *map_name);
void		find_player(t_game_map *game_map, int *x, int *y);

t_window	*start_render(t_game_map *game_map);

t_game_map	*control_player(int keycode, t_game_map *inj_game_map);

t_game_map	*keycode_action(t_game_map *game_map, int keycode);

void		render(t_game_map *game_map, t_window *params);

int			window_height(t_game_map *game_map);
int			window_width(t_game_map *game_map);
int			window_vertical_center(t_game_map *game_map);
int			window_horizontal_center(t_game_map *game_map);

void		free_map_data(char **map_data, int size);

void		wall_image(t_window *params, t_game_map *map);
void		collectible_image(t_window *params, t_game_map *map);
void		exit_image(t_window *params, t_game_map *map);
void		bg_image(t_window *params, t_game_map *map);
void		player_image(t_window *params, t_game_map *map);

int			game_over(t_game_map *map, t_window *params);

void		free_all(t_game_map *game_map, t_window *params);
void		file_error(t_game_map *map);
void		map_error(t_game_map *map, int size);

#endif
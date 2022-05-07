/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:34:06 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 16:49:28 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_image(t_window *params, t_game_map *map)
{
	char		*player;
	void		*img;
	int			pos[2];

	if (map->player_direction == 'U')
		player = PLAYER_U_IMG;
	if (map->player_direction == 'D')
		player = PLAYER_D_IMG;
	if (map->player_direction == 'L')
		player = PLAYER_L_IMG;
	if (map->player_direction == 'R')
		player = PLAYER_R_IMG;
	img = mlx_xpm_file_to_image(params->mlx, player, &pos[0], &pos[1]);
	map->player = img;
}

void	wall_image(t_window *params, t_game_map *map)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = WALL_IMG;
	if (!img)
		img = mlx_xpm_file_to_image(params->mlx, wall, &pos[0], &pos[1]);
	map->wall = img;
}

void	collectible_image(t_window *params, t_game_map *map)
{
	char		*collectible;
	static void	*img;
	int			pos[2];

	collectible = COLLECTIBLE_IMG;
	if (!img)
		img = mlx_xpm_file_to_image(params->mlx, collectible, &pos[0], &pos[1]);
	map->collectible = img;
}

void	exit_image(t_window *params, t_game_map *map)
{
	char		*exit;
	static void	*img;
	int			pos[2];

	exit = EXIT_IMG;
	if (!img)
		img = mlx_xpm_file_to_image(params->mlx, exit, &pos[0], &pos[1]);
	map->exit = img;
}

void	bg_image(t_window *params, t_game_map *map)
{
	char		*bg;
	static void	*img;
	int			pos[2];

	bg = EMPTY_IMG;
	if (!img)
		img = mlx_xpm_file_to_image(params->mlx, bg, &pos[0], &pos[1]);
	map->bg = img;
}

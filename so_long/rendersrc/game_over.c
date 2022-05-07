/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:06:59 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 15:45:54 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game_map *game_map, t_window *params)
{
	static t_game_map	*static_game_map = NULL;
	static t_window		*static_params = NULL;

	if (static_game_map && !game_map)
	{
		free_map_data(static_game_map->data, static_game_map->map_height);
		free(static_game_map);
		static_game_map = NULL;
	}
	if (static_params && !params)
	{
		free(static_params);
		static_params = NULL;
	}
	if (game_map)
		static_game_map = game_map;
	if (params)
		static_params = params;
}

static int	game_won(t_game_map *m, void **p, int *w_v)
{
	m->game_over = 1;
	mlx_string_put(p[0], p[1], w_v[1], w_v[0], COLOR, GAME_WON);
	control_player(-2, m);
	return (1);
}

int	game_over(t_game_map *map, t_window *params)
{
	int		w_center[2];
	void	*p[2];
	int		pos[2];

	w_center[0] = window_vertical_center(map);
	w_center[1] = window_horizontal_center(map);
	p[0] = params->mlx;
	p[1] = params->win;
	pos[0] = map->player_position_y / TILE_WIDTH;
	pos[1] = map->player_position_x / TILE_WIDTH;
	if (map->data[pos[0]][pos[1]] == 'E' && \
		map->max_score == map->game_score)
		return (game_won(map, p, w_center));
	return (0);
}

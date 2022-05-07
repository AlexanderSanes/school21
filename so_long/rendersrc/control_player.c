/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:21 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 15:15:29 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game_map	*check_collect(t_game_map *game_map)
{
	int	x;
	int	y;

	y = game_map->player_position_y / TILE_WIDTH;
	x = game_map->player_position_x / TILE_WIDTH;
	if (game_map->data[y][x] == 'C')
	{
		game_map->data[y][x] = '0';
		game_map->game_score++;
	}
	return (game_map);
}

t_game_map	*control_player(int keycode, t_game_map *game_map)
{
	static t_game_map	*static_game_map = NULL;

	if (game_map)
	{
		static_game_map = game_map;
		find_player(game_map, &game_map->player_position_x,
			&game_map->player_position_y);
	}
	else
	{
		static_game_map = keycode_action(static_game_map, keycode);
		static_game_map = check_collect(static_game_map);
	}
	return (static_game_map);
}

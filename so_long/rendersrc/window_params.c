/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:11:17 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 15:07:23 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_height(t_game_map *game_map)
{
	return ((game_map->map_height) * TILE_WIDTH);
}

int	window_width(t_game_map *game_map)
{
	return ((game_map->map_length) * TILE_WIDTH);
}

int	window_vertical_center(t_game_map *game_map)
{
	return (((game_map->map_height - 1) * TILE_WIDTH) / 2);
}

int	window_horizontal_center(t_game_map *game_map)
{
	return (((game_map->map_length - 1) * TILE_WIDTH) / 2);
}

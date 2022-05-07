/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:33:29 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 15:44:51 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_step(t_game_map *map)
{
	if (!map->game_over)
	{
		ft_putnbr_fd(map->steps, 1);
		write(1, "\n", 1);
	}
}

static int	check_wall(t_game_map *game_map, int x, int y)
{
	int	line;
	int	count;

	line = 0;
	count = 0;
	if (game_map->data[y / TILE_WIDTH][x / TILE_WIDTH] == '1')
		return (0);
	return (1);
}

static t_game_map	*move_vertical(t_game_map *game_map, int dir)
{
	int	x;
	int	y;

	x = game_map->player_position_x;
	y = game_map->player_position_y;
	if (dir == -1)
		game_map->player_direction = 'U';
	else
		game_map->player_direction = 'D';
	if (check_wall(game_map, x, y + (TILE_WIDTH * dir)))
	{
		game_map->player_position_y += dir * TILE_WIDTH;
		game_map->steps++;
		print_step(game_map);
	}
	return (game_map);
}

static t_game_map	*move_horizontal(t_game_map *game_map, int dir)
{
	int	x;
	int	y;

	x = game_map->player_position_x;
	y = game_map->player_position_y;
	if (dir == 1)
		game_map->player_direction = 'R';
	else
		game_map->player_direction = 'L';
	if (check_wall(game_map, x + (TILE_WIDTH * dir), y))
	{
		game_map->player_position_x += dir * TILE_WIDTH;
		game_map->steps++;
		print_step(game_map);
	}
	return (game_map);
}

t_game_map	*keycode_action(t_game_map *game_map, int keycode)
{
	if (keycode == 1)
		return (move_vertical(game_map, 1));
	if (keycode == 13)
		return (move_vertical(game_map, -1));
	if (keycode == 2)
		return (move_horizontal(game_map, 1));
	if (keycode == 0)
		return (move_horizontal(game_map, -1));
	return (game_map);
}

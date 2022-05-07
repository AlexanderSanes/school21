/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:02:25 by rdeanne           #+#    #+#             */
/*   Updated: 2022/04/15 17:19:04 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "so_long.h"

void	init_map(t_game_map *map)
{
	map->map_height = 0;
	map->map_length = 0;
	map->data = NULL;
	map->game_score = 0;
	map->game_over = 0;
	map->max_score = 0;
	map->steps = 0;
	map->player_position_x = 0;
	map->player_position_y = 0;
	map->player_direction = 'R';
}

int	check_map_name(char *map_name)
{
	return (ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".ber", 4) == 0);
}

int	check_map(t_game_map map)
{
	int	i;
	int	p;
	int	e;
	int	j;

	i = -1;
	p = 0;
	e = 0;
	while (++i < map.map_height)
	{
		j = -1;
		while (++j < map.map_length)
		{
			if ((i == 0 || i == map.map_height - 1 \
				|| j == 0 || j == map.map_length - 1) && map.data[i][j] != '1')
				return (0);
			if (map.data[i][j] == PLAYER)
				p++;
			if (map.data[i][j] == EXIT)
				e++;
			if (e > 1 || p > 1)
				return (0);
		}
	}
	return (!(e == 0 || p == 0));
}

void	find_player(t_game_map *game_map, int *x, int *y)
{
	int	count_y;
	int	count_x;

	count_y = 0;
	count_x = 0;
	while (count_y < game_map->map_height)
	{
		count_x = 0;
		while (count_x < game_map->map_length)
		{
			if (game_map->data[count_y][count_x] == 'P')
			{
				*x = count_x * TILE_WIDTH;
				*y = count_y * TILE_WIDTH;
				return ;
			}
			count_x++;
		}
		count_y++;
	}
}

void	free_map_data(char **map_data, int size)
{
	int	count;

	count = 0;
	if (!map_data)
		return ;
	while (count < size)
	{
		free(map_data[count]);
		count++;
	}
	free(map_data);
	map_data = NULL;
}

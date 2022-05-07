/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/05 16:52:19 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_window *params, void *p, int x, int y)
{
	if (params && p)
		mlx_put_image_to_window(params->mlx, params->win, p, x, y);
}

static void	put_player(t_window *params, t_game_map *game_map)
{
	int		pos[2];

	pos[0] = game_map->player_position_x;
	pos[1] = game_map->player_position_y;
	player_image(params, game_map);
	put_image(params, game_map->player, pos[0], pos[1]);
}

static void	tile(char t, t_window *v, int *pos, t_game_map *map)
{
	put_image(v, map->bg, pos[0], pos[1]);
	if (t == '1')
		put_image(v, map->wall, pos[0], pos[1]);
	if (t == 'C')
		put_image(v, map->collectible, pos[0], pos[1]);
	if (t == 'E')
		put_image(v, map->exit, pos[0], pos[1]);
}

static void	draw_map(t_window *params, t_game_map *game_map)
{
	int		count_x;
	int		count_y;
	char	current;
	int		pos[2];

	count_y = 0;
	pos[1] = 0;
	while (count_y < game_map->map_height && params)
	{
		count_x = 0;
		pos[0] = 0;
		while (count_x < game_map->map_length)
		{
			current = game_map->data[count_y][count_x];
			tile(current, params, pos, game_map);
			count_x++;
			pos[0] += TILE_WIDTH;
		}
		pos[1] += TILE_WIDTH;
		count_y++;
	}
	put_player(params, game_map);
}

void	render(t_game_map *game_map, t_window *params)
{
	void	*p[2];

	p[0] = params->mlx;
	p[1] = params->win;
	if (game_map->data && params && (!game_map->game_over))
	{
		mlx_clear_window(params->mlx, params->win);
		if ((!game_over(game_map, params)) && p[1] && p[0])
			draw_map(params, game_map);
	}
}

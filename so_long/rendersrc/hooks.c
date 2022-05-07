/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:31:57 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 15:28:08 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_hook(void)
{
	free_all(NULL, NULL);
	exit(0);
}

static void	set_images(t_game_map *map, t_window *params)
{
	collectible_image(params, map);
	wall_image(params, map);
	exit_image(params, map);
	bg_image(params, map);
	player_image(params, map);
}

static int	key_hook(int keycode, t_window *params)
{	
	static t_game_map	*static_game_map = NULL;

	if (keycode == 53)
	{
		mlx_destroy_window(params->mlx, params->win);
		free_all(NULL, NULL);
		exit(0);
		return (0);
	}
	if (params)
	{
		static_game_map = control_player(keycode, NULL);
		render(static_game_map, params);
	}
	return (1);
}

t_window	*start_render(t_game_map *game_map)
{
	t_window	*params;
	int			ww;
	int			wh;

	params = malloc(sizeof(t_window));
	if (!params)
		return (NULL);
	params->mlx = mlx_init();
	if (!params->mlx)
		return (NULL);
	ww = window_width(game_map);
	wh = window_height(game_map);
	params->win = mlx_new_window(params->mlx, ww, wh, "rdeanne solong");
	set_images(game_map, params);
	free_all(game_map, params);
	key_hook(-1, params);
	mlx_key_hook(params->win, key_hook, params);
	mlx_hook(params->win, 17, 0, exit_hook, params);
	mlx_loop_hook(params->mlx, NULL, params);
	mlx_loop(params->mlx);
	return (params);
}

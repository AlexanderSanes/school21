/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:30:16 by rdeanne           #+#    #+#             */
/*   Updated: 2022/04/12 15:36:33 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game_map *map, int size)
{
	free_map_data(map->data, size);
	write(1, "map error!\n", 11);
	exit(0);
}

void	file_error(t_game_map *map)
{
	free(map);
	write(1, "Open file error!\n", 17);
	exit(0);
}

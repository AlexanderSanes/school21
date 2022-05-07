/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:45:36 by rdeanne           #+#    #+#             */
/*   Updated: 2022/04/12 15:33:54 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "so_long.h"

static int	max_score(t_game_map *game_map)
{
	int	score;
	int	count_y;
	int	count_x;

	score = 0;
	count_y = 0;
	count_x = 0;
	while (count_y < game_map->map_height)
	{
		count_x = 0;
		while (count_x < game_map->map_length)
		{
			if (game_map->data[count_y][count_x] == 'C')
				score++;
			count_x++;
		}
		count_y++;
	}
	return (score);
}

static char	*parse_map_line(char *line)
{
	char	*arr;
	int		i;

	arr = malloc(sizeof(char) * ft_strlen(line));
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '0')
			arr[i] = '0';
		else if (line[i] == '1')
			arr[i] = '1';
		else if (line[i] == 'C')
			arr[i] = 'C';
		else if (line[i] == 'E')
			arr[i] = 'E';
		else if (line[i] == 'P')
			arr[i] = 'P';
		else
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

static void	set_map_size(t_game_map *map, char *map_name)
{
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		file_error(map);
	line = get_next_line(fd);
	map->map_height = 0;
	map->map_length = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	while (line != NULL)
	{
		map->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	map->data = malloc(sizeof(int *) * (map->map_height + 1));
	if (!map->data)
		exit(0);
}

static void	set_map_data(t_game_map *map, char *map_name)
{
	int		fd;
	char	*line;
	int		i;
	int		len;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		file_error(map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		map->data[i] = parse_map_line(line);
		if (!map->data[i++] || map->map_length != len)
			map_error(map, i);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->max_score = max_score(map);
	close(fd);
}

t_game_map	*parse_map(char *map_name)
{
	t_game_map	*map;

	map = malloc(sizeof(t_game_map));
	if (!map)
		return (NULL);
	free_all(map, NULL);
	init_map(map);
	set_map_size(map, map_name);
	set_map_data(map, map_name);
	return (map);
}

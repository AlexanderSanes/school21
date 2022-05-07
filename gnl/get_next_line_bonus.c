/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:39:48 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/27 12:39:49 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*read_to_endl(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (rd && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buf[rd] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*update_prev(char *str)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_line(char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*prev[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev[fd] = read_to_endl(fd, prev[fd]);
	if (!prev[fd])
		return (NULL);
	res = get_line(prev[fd]);
	prev[fd] = update_prev(prev[fd]);
	return (res);
}

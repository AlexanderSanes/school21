/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:05 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/11 12:45:08 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	is_inset(char	c, char const	*set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	set_startend(size_t	*start, size_t	*end, \
						char const	*s, char const	*set)
{
	*start = 0;
	while (is_inset(s[*start], set))
		(*start)++;
	*end = ft_strlen(s) - 1;
	if (*start == ft_strlen(s))
		*end = *start;
	else
		while (is_inset(s[*end], set))
			(*end)--;
}

char	*ft_strtrim(char const	*s, char const	*set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	start = 0;
	end = 0;
	set_startend(&start, &end, s, set);
	res = malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

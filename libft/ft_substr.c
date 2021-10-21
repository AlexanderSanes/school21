/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:00 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/11 12:45:02 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	char	*res;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		start = (unsigned int)size;
	if (start + len > size)
		len = size - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, s + start, len);
	res[len] = '\0';
	return (res);
}

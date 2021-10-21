/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:43:59 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/08 12:44:04 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict	dst, const char *restrict	src,
					size_t	dstsize)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (dst[n] != '\0' && n < dstsize)
		n++;
	i = n;
	while (src[n - i] && n + 1 < dstsize)
	{
		dst[n] = src[n - i];
		n++;
	}
	if (i < dstsize)
		dst[n] = '\0';
	return (i + ft_strlen(src));
}

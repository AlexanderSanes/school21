/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:31 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/08 12:47:32 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	n;
	size_t	k;
	size_t	needlelen;

	n = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	needlelen = ft_strlen(needle);
	while (haystack[n] && n < len)
	{
		k = 0;
		while (haystack[n + k] == needle[k] && n + k < len)
			k++;
		if (k == needlelen)
			return ((char *)(&haystack[n]));
		n++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:32 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/08 12:47:33 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_find;

	last_find = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_find = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last_find);
}

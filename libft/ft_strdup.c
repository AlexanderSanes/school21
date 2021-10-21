/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:44:09 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/08 12:44:11 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char	*s1)
{
	char	*res;

	res = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1[0] == '\0')
	{
		res[0] = '\0';
		return (res);
	}
	if (!ft_strlcpy(res, s1, ft_strlen(s1) + 1))
		return (NULL);
	return (res);
}

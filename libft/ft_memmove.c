/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:44:21 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/20 15:32:55 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (src < dst)
		while (len--)
			tmp_dst[len] = tmp_src[len];
	else
		while (len--)
			*tmp_dst++ = *tmp_src++;
	return (dst);
}

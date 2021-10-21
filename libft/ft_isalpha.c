/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:44:50 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/20 15:32:39 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int	c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int	c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int	c)
{
	return (ft_isupper(c) || ft_islower(c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:15 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:38:24 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_format_putchar_fd(char c, t_print plist)
{
	int	width;

	width = max(plist.width, 1);
	if (!plist.f.minus)
	{
		put_alignment(width - 1, 0, plist.f, 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		put_alignment(width - 1, 0, plist.f, 1);
	}
	return (width);
}

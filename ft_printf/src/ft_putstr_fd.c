/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:16 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:38:43 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putstr_fd(char *s, int fd)
{
	
	if (s)
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	write(fd, "(null)", 6);
	return (6);
}

int	ft_format_putstr_fd(char *s, t_print plist)
{
	int	width;

	if (!s)
	{
		width = plist.width;
		put_alignment(width - 6, plist.prec, plist.f, 1);
		ft_putstr_fd(s, 1);
		return (width + 6);
	}
	width = max(plist.width, ft_strlen(s)) - ft_strlen(s) + 1;
	if (!plist.f.minus)
	{
		put_alignment(width - 1, 0, plist.f, 1);
		ft_putstr_fd(s, 1);
	}
	else
	{
		ft_putstr_fd(s, 1);
		put_alignment(width - 1, 0, plist.f, 1);
	}
	return (width + ft_strlen(s) - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:38:36 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:38:38 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putptr_fd(char *s, int i, int width, t_print plist)
{
	if (plist.f.minus)
	{
		put_sign(1, plist.f, 1);
		write(1, "0x", 2);
		while ((size_t)i < 2 * sizeof(intptr_t))
			ft_putchar_fd(s[i++], 1);
		put_alignment(width, plist.prec - 1, plist.f, 1);
	}
	else
	{
		if (plist.f.zero)
		{
			put_sign(1, plist.f, 1);
			write(1, "0x", 2);
		}
		put_alignment(width, plist.prec - 1, plist.f, 1);
		if (!plist.f.zero)
		{
			put_sign(1, plist.f, 1);
			write(1, "0x", 2);
		}
		while ((size_t)i < 2 * sizeof(intptr_t))
			ft_putchar_fd(s[i++], 1);
	}
}

void	print_nullptr(int width, t_print plist, int fd)
{
	if (plist.f.minus)
	{
		write(fd, "0x0", 3);
		put_alignment(width, plist.prec - 1, plist.f, fd);
	}
	else
	{
		put_alignment(width, plist.prec - 1, plist.f, fd);
		write(fd, "0x0", 3);
	}
}

int	ft_format_putptr_fd(void *a, t_print plist)
{
	int			i;
	intptr_t	p;
	char		s[2 * sizeof(p) + 1];
	int			width;
	int			len;

	if (!a)
	{
		print_nullptr(max(max(3, plist.width), plist.prec) - 3, plist, 1);
		return (max(max(3, plist.width), plist.prec));
	}
	len = 18 + (plist.f.plus || plist.f.space);
	p = (intptr_t) a;
	i = 2 * sizeof(p) - 1;
	s[i + 1] = '\0';
	while (i >= 0)
	{
		s[i--] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
	}
	while (s[++i] == '0')
		len--;
	width = max(max(len, plist.width), plist.prec);
	ft_putptr_fd(s, i, width - len, plist);
	return (width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase16_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:38:05 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:38:08 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	print_0x(int (*func)(int), int fd)
{
	write(fd, "0", 1);
	ft_putchar_fd(func('x'), fd);
}

void	ft_putbase16_fd(char *s, int width, t_print plist,
		int (*func)(int))
{
	int	i;

	i = 0;
	if (plist.f.minus)
	{
		put_sign(1, plist.f, 1);
		if (plist.f.hash)
			print_0x(func, 1);
		while (s[i])
			ft_putchar_fd(func(s[i++]), 1);
		put_alignment(width, plist.prec - 1, plist.f, 1);
	}
	else
	{
		if (plist.f.hash && plist.f.zero)
			print_0x(func, 1);
		put_alignment(width, plist.prec - 1, plist.f, 1);
		if (plist.f.hash && !plist.f.zero)
			print_0x(func, 1);
		while (s[i])
			ft_putchar_fd(func(s[i++]), 1);
	}
}

void	print_0ptr(int width, t_print plist, t_flags f, int fd)
{
	if (f.minus)
	{
		write(fd, "0", 1);
		put_alignment(width, plist.prec - 1, f, fd);
	}
	else
	{
		put_alignment(width, plist.prec - 1, f, fd);
		write(fd, "0", 1);
	}
}

int	ft_format_putbase16_fd(int a, t_print plist, int (*func)(int))
{
	int			i;
	int			p;
	char		s[2 * sizeof(p) + 1];
	int			len;
	int			width;

	if (!a)
	{
		print_0ptr(max(max(1, plist.width), plist.prec) - 1, plist, plist.f, 1);
		return (max(max(1, plist.width), plist.prec));
	}
	len = 8 + (plist.f.plus || plist.f.space) + 2 * plist.f.hash;
	p = (int) a;
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
	ft_putbase16_fd(&s[i], width - len, plist, func);
	return (width);
}

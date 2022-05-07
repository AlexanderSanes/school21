/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:20 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:38:34 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	ft_putnbr_fd(long n, int fd)
{
	if (n)
		ft_putnbr_fd(n / 10, fd);
	if (n != 0)
		ft_putchar_fd((n % 10) + '0', fd);
}

void	formated_putnbr(long n, long longn, int width, t_print plist)
{
	if (plist.f.minus)
	{
		put_sign(n, plist.f, 1);
		if (!n)
			ft_putchar_fd('0', 1);
		else
			ft_putnbr_fd(longn, 1);
		put_alignment(width, plist.prec - 1, plist.f, 1);
	}
	else
	{
		if (plist.f.zero)
			put_sign(n, plist.f, 1);
		put_alignment(width, plist.prec - 1, plist.f, 1);
		if (!plist.f.zero)
			put_sign(n, plist.f, 1);
		if (!n)
			ft_putchar_fd('0', 1);
		else
			ft_putnbr_fd(longn, 1);
	}
}

int	ft_format_unsigned_putnbr_fd(unsigned int n, t_print plist)
{
	long	longn;
	int		dim;
	int		width;

	longn = (long)n;
	dim = dim_of_num(longn) + (plist.f.plus || plist.f.space);
	width = max(dim, plist.width);
	formated_putnbr(longn, longn, width - dim, plist);
	return (width);
}

int	ft_format_putnbr_fd(int n, t_print plist)
{
	long	longn;
	int		dim;
	int		width;

	longn = (long)n;
	if (longn < 0)
		longn *= -1;
	dim = dim_of_num(longn) + (plist.f.plus || n < 0 || plist.f.space);
	width = max(max(dim, plist.width), plist.prec);
	formated_putnbr(n, longn, width - dim, plist);
	return (width);
}

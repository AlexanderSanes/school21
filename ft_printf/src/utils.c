/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:41:25 by rdeanne           #+#    #+#             */
/*   Updated: 2022/01/08 14:41:26 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	put_alignment(int width, int prec, t_flags f, int fd)
{
	if (f.zero && !f.minus)
		while (width-- > 0)
			ft_putchar_fd('0', fd);
	else
	{
		if (prec > 0)
		{
			while (width-- - prec > 0)
				ft_putchar_fd(' ', fd);
			while (prec--)
				ft_putchar_fd('0', fd);
		}
		else
			while (width-- > 0)
				ft_putchar_fd(' ', fd);
	}
}

int	put_sign(long longn, t_flags f, int fd)
{
	if (longn < 0)
	{
		ft_putchar_fd('-', fd);
		return (1);
	}
	else if (f.plus)
	{
		ft_putchar_fd('+', fd);
		return (1);
	}
	else if (f.space)
	{
		ft_putchar_fd(' ', fd);
		return (1);
	}
	return (0);
}

void	init_flags(t_flags *f)
{
	f->minus = 0;
	f->space = 0;
	f->plus = 0;
	f->zero = 0;
	f->hash = 0;
}

int	dim_of_num(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

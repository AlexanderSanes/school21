/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:20 by rdeanne           #+#    #+#             */
/*   Updated: 2021/10/20 15:32:59 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

static void	recursive_putnbr(long	n, int	fd)
{
	if (n)
		recursive_putnbr(n / 10, fd);
	if (n != 0)
		ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int	n, int	fd)
{
	long	longn;

	longn = (long)n;
	if (longn == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (longn < 0)
		{
			write(fd, "-", 1);
			longn *= -1;
		}
		recursive_putnbr(longn, fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:45:54 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 11:28:57 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "utils.h"

void	ft_putchar_fd(char c, int fd	)
{
	write(fd, &c, 1);
}

void	recursive_putnbr(long n, int fd)
{
	if (n)
		recursive_putnbr(n / 10, fd);
	if (n != 0)
		ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
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

int	ft_atoi(const char *str)
{
	char				sign;
	unsigned long long	num;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > LONG_MAX - 1 && sign == 1)
		return (0);
	if (num > LONG_MAX && sign == 0)
		return (-1);
	if (sign)
		return (-num);
	else
		return (num);
}

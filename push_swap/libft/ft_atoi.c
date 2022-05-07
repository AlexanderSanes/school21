/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:52 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/11 15:24:01 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	char				sign;
	unsigned long		num;

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
	if (num > (unsigned long)INT_MAX + 1 && sign == 1)
		return (1);
	if (num > (unsigned long)INT_MAX && sign == 0)
		return (-1);
	if (sign)
		return (-num);
	else
		return (num);
}

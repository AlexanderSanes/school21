/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:41:27 by rdeanne           #+#    #+#             */
/*   Updated: 2022/01/08 14:41:29 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	parse_slash(char c, t_print *plist)
{
	if (c == 'n')
	{
		write(1, "\n", 1);
		plist->len++;
		return (1);
	}
	return (0);
}

int	parse_param(char c, t_print *plist)
{
	if (c == 'd' || c == 'i')
		return (ft_format_putnbr_fd(va_arg(plist->argptr, int), *plist));
	if (c == 'u')
		return (ft_format_unsigned_putnbr_fd(va_arg(plist->argptr, int),
				*plist));
	if (c == 'c')
		return (ft_format_putchar_fd(va_arg(plist->argptr, int),
				*plist));
	if (c == 's')
		return (ft_format_putstr_fd(va_arg(plist->argptr, char *),
				*plist));
	if (c == 'p')
		return (ft_format_putptr_fd(va_arg(plist->argptr, void *),
				*plist));
	if (c == 'x')
		return (ft_format_putbase16_fd(va_arg(plist->argptr, intptr_t),
				*plist, ft_tolower));
	if (c == 'X')
		return (ft_format_putbase16_fd(va_arg(plist->argptr, intptr_t),
				*plist, ft_toupper));
	if (c == '%')
		return (ft_format_putchar_fd('%', *plist));
	return (0);
}

int	parse_flags(int i, const char *str, t_print *plist)
{
	if (str[i] == '+')
		plist->f.plus = 1;
	if (str[i] == ' ')
		plist->f.space = 1;
	if (!ft_isdigit(str[i - 1]) && str[i] == '0')
		plist->f.zero = 1;
	else if (ft_isdigit(str[i]))
	{
		while (str[i] == '0')
			i++;
		plist->width = ft_atoi(&str[i]);
		i += dim_of_num(plist->width) - 1;
	}
	if (str[i] == '#')
		plist->f.hash = 1;
	if (str[i] == '-')
		plist->f.minus = 1;
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
	{
		while (str[i] == '0' || str[i] == '.')
			i++;
		plist->prec = ft_atoi(&str[i]);
		i += dim_of_num(plist->prec) - 1;
	}
	return (++i);
}

int	parse_percent(const char *str, t_print *plist)
{
	int		i;

	i = 0;
	init_flags(&(plist->f));
	while (!ft_strrchr(PARAMS, str[i]))
	{
		i += parse_flags(0, &str[i], plist);
	}
	plist->len += parse_param(str[i], plist);
	return (i + 1);
}

void	parse_printf(const char *str, t_print *plist)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += parse_percent(&str[i + 1], plist);
		else
		{
			write(1, &str[i], 1);
			plist->len++;
		}
		i++;
	}
}

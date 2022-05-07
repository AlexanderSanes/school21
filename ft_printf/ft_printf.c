/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:39:48 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:39:50 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	t_print	plist;

	plist.len = 0;
	plist.prec = 0;
	plist.width = 0;
	va_start(plist.argptr, str);
	parse_printf(str, &plist);
	va_end(plist.argptr);
	return (plist.len);
}

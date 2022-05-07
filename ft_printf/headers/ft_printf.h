/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:39:17 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:39:20 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PARAMS "cspdiuxX%"
# define FLAGS " .#-+"

# include <stdarg.h>

typedef struct s_flags
{
	int	plus;
	int	space;
	int	hash;
	int	zero;
	int	minus;
}	t_flags;

typedef struct s_print {
	int		len;
	int		width;
	int		prec;
	t_flags	f;
	va_list	argptr;

}	t_print;

int		ft_printf(const char *str, ...);
void	parse_printf(const char *str, t_print *plist);
void	print_info_plist(t_print plist);
void	init_flags(t_flags *f);

#endif

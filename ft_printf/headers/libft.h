/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:45 by rdeanne           #+#    #+#             */
/*   Updated: 2021/12/24 14:39:16 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include "ft_printf.h"

int		max(int a, int b);
int		put_sign(long longn, t_flags f, int fd);
void	put_alignment(int width, int prec, t_flags f, int fd);
int		dim_of_num(long n);

int		ft_isdigit(int c);
size_t	ft_strlen(const char	*s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putchar_fd(char c, int fd);
int		ft_format_putchar_fd(char c, t_print plist);
int		ft_format_putnbr_fd(int n, t_print plist);
int		ft_format_unsigned_putnbr_fd(unsigned int n, t_print plist);
// int		ft_putstr_fd(char	*s, int fd);
int		ft_format_putstr_fd(char *s, t_print plist);
// int		ft_putptr_fd(void	*s, int fd);
int		ft_format_putptr_fd(void *a, t_print plist);
int		ft_format_putbase16_fd(int a, t_print plist, int (*func)(int));
char	*ft_strrchr(const char	*s, int c);
int		ft_atoi(const char *str);
#endif

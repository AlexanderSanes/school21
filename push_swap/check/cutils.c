/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:43:33 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:44:47 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

int	check_instructions(char *line, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (csa(a));
	if (!(ft_strcmp(line, "sb\n")))
		return (csb(b));
	if (!(ft_strcmp(line, "ss\n")))
		return (css(a, b));
	if (!(ft_strcmp(line, "pa\n")))
		return (cpa(a, b));
	if (!(ft_strcmp(line, "pb\n")))
		return (cpb(a, b));
	if (!(ft_strcmp(line, "ra\n")))
		return (cra(a));
	if (!(ft_strcmp(line, "rb\n")))
		return (crb(b));
	if (!(ft_strcmp(line, "rr\n")))
		return (crr(a, b));
	if (!(ft_strcmp(line, "rra\n")))
		return (crra(a));
	if (!(ft_strcmp(line, "rrb\n")))
		return (crrb(b));
	if (!(ft_strcmp(line, "rrr\n")))
		return (crrr(a, b));
	return (0);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!(check_instructions(line, a, b)))
		{
			free(line);
			write(2, "Error\n", 6);
			return ;
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	free(line);
	if ((is_sorted(*a)) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

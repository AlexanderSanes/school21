/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:14:32 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/03 17:24:43 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	*a = swap_top(*a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	*b = swap_top(*b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	*a = swap_top(*a);
	*b = swap_top(*b);
	write(1, "ss\n", 3);
}

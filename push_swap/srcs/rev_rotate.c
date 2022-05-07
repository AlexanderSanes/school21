/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:14:22 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/03 17:28:41 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	*a = reverse_rotate_stack(*a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	*b = reverse_rotate_stack(*b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	*a = reverse_rotate_stack(*a);
	*b = reverse_rotate_stack(*b);
	write(1, "rrr\n", 4);
}

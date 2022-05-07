/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:14:36 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 11:12:14 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	*a = rotate_stack(*a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	*b = rotate_stack(*b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	*a = rotate_stack(*a);
	*b = rotate_stack(*b);
	write(1, "rr\n", 3);
}

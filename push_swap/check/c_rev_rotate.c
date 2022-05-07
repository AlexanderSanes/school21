/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rev_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:36:28 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 12:44:19 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	crra(t_stack **a)
{
	*a = reverse_rotate_stack(*a);
	return (1);
}

int	crrb(t_stack **b)
{
	*b = reverse_rotate_stack(*b);
	return (1);
}

int	crrr(t_stack **a, t_stack **b)
{
	*a = reverse_rotate_stack(*a);
	*b = reverse_rotate_stack(*b);
	return (1);
}

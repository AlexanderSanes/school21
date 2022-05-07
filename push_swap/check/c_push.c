/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:36:30 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:40:43 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cpa(t_stack **a, t_stack **b)
{
	if (!*b)
		return (1);
	*a = push_front(*a, (*b)->value);
	*b = pop_front(*b);
	return (1);
}

int	cpb(t_stack **a, t_stack **b)
{
	if (!*a)
		return (1);
	*b = push_front(*b, (*a)->value);
	*a = pop_front(*a);
	return (1);
}

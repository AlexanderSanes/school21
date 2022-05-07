/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:14:26 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:40:35 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	if (!*b)
		return ;
	*a = push_front(*a, (*b)->value);
	*b = pop_front(*b);
}

void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	if (!*a)
		return ;
	*b = push_front(*b, (*a)->value);
	*a = pop_front(*a);
}

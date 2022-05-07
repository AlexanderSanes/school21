/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:36:21 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 12:44:27 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	csa(t_stack **a)
{
	*a = swap_top(*a);
	return (1);
}

int	csb(t_stack **b)
{
	*b = swap_top(*b);
	return (1);
}

int	css(t_stack **a, t_stack **b)
{
	*a = swap_top(*a);
	*b = swap_top(*b);
	return (1);
}

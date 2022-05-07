/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:36:26 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:41:00 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cra(t_stack **a)
{
	*a = rotate_stack(*a);
	return (1);
}

int	crb(t_stack **b)
{
	*b = rotate_stack(*b);
	return (1);
}

int	crr(t_stack **a, t_stack **b)
{
	*a = rotate_stack(*a);
	*b = rotate_stack(*b);
	return (1);
}

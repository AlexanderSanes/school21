/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:06:43 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 10:47:29 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->next->value < (*a)->value)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	min;
	int	max;

	min = min_index(*a);
	max = max_index(*a);
	if ((*a)->value == max)
		ra(a);
	if ((*a)->value == min && (*a)->next->value == max)
	{
		rra(a);
		sa(a);
	}
	if ((*a)->value != min && (*a)->value > (*a)->next->value)
		sa(a);
	if ((*a)->value != min && (*a)->value < (*a)->next->value)
		rra(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 2)
	{
		min = min_index(*a);
		if ((*a)->value > min && !is_more_on_left(*a, min))
			ra(a);
		else if ((*a)->value > min && is_more_on_left(*a, min))
			rra(a);
		else
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->value != min_index(*a))
		sa(a);
	while ((*b) != NULL)
		pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 3)
	{
		min = min_index(*a);
		if ((*a)->value > min && !is_more_on_left(*a, min))
			ra(a);
		else if ((*a)->value > min && is_more_on_left(*a, min))
			rra(a);
		else
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->value != min_index(*a))
		sa(a);
	while ((*b) != NULL)
		pa(a, b);
}

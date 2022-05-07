/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:54:50 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 09:52:35 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_sort(t_stack **a, t_stack **b)
{
	int	max;

	while ((*b) != NULL)
	{
		max = max_index(*b);
		if (!b)
			break ;
		if ((*b)->value != max && \
			!is_more_on_left(*b, max))
			rb(b);
		else if ((*b)->value != max && \
				is_more_on_left(*b, max))
			rrb(b);
		else if ((*b)->value == max)
			pa(a, b);
	}
}

void	sort_100(t_stack **a, t_stack **b)
{
	int	l;

	l = 0;
	while ((*a) != NULL)
	{
		if (l > 1 && (*a)->value <= l)
		{
			pb(a, b);
			l++;
			rb(b);
		}
		else if ((*a)->value <= l + 15)
		{
			pb(a, b);
			l++;
		}
		else if ((*a)->value >= l)
			ra(a);
	}
	back_sort(a, b);
}

void	sort_500(t_stack **a, t_stack **b)
{
	int	l;

	l = 0;
	while ((*a) != NULL)
	{
		if (l > 1 && (*a)->value <= l)
		{
			pb(a, b);
			l++;
			rb(b);
		}
		else if ((*a)->value <= l + 30)
		{
			pb(a, b);
			l++;
		}
		else if ((*a)->value >= l)
			ra(a);
	}
	back_sort(a, b);
}

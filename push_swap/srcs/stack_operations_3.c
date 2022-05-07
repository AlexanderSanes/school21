/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:11:42 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:44:57 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*head;

	head = a;
	while (a != head->next)
	{
		if ((head->value + 1) == head->next->value)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	if (!a)
		return ;
	while (*a)
		*a = pop_front(*a);
}

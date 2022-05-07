/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:06:01 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 11:13:41 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int	stack_size(t_stack *a)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = a;
	while (head->next != a)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	max_index(t_stack *a)
{
	int		max;
	t_stack	*head;

	head = a;
	max = head->value;
	head = head->next;
	while (a != head)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}

int	min_index(t_stack *a)
{
	int		min;
	t_stack	*head;

	head = a;
	min = head->value;
	head = head->next;
	while (a != head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}

int	is_more_on_left(t_stack *a, int index)
{
	int		left;
	int		right;
	t_stack	*tmp;

	left = 0;
	right = 0;
	tmp = a;
	while (tmp->value != index)
	{
		left++;
		tmp = tmp->next;
	}
	while (tmp->next != a)
	{
		right++;
		tmp = tmp->next;
	}
	return (left > right);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:01:07 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 11:12:59 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>

t_stack	*init_stack(int a)
{
	t_stack	*st;

	st = (malloc(sizeof(t_stack)));
	if (!st)
		return (NULL);
	st->value = a;
	st->next = st;
	st->prev = st;
	return (st);
}

int	*copy_arr(int *arr, int size)
{
	int	i;
	int	*copy;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

int	get_index(int *arr, int value)
{
	int	i;

	i = 0;
	while (arr[i] != value)
		i++;
	return (i);
}

int	*get_index_arr(int *arr, int size)
{
	int	*index_arr;
	int	*sorted_arr;
	int	i;

	i = 0;
	sorted_arr = copy_arr(arr, size);
	bubble_sort_array(sorted_arr, size);
	index_arr = malloc(sizeof(int) * size);
	if (!index_arr)
		return (NULL);
	while (i < size)
	{
		index_arr[i] = get_index(sorted_arr, arr[i]);
		i++;
	}
	free(sorted_arr);
	return (index_arr);
}

t_stack	*fill_stack(int *arr, int size)
{
	t_stack	*new_head;
	int		i;
	int		*index_arr;

	i = 0;
	index_arr = get_index_arr(arr, size);
	new_head = init_stack(index_arr[i++]);
	while (i < size)
		new_head = push_front(new_head, index_arr[i++]);
	free(index_arr);
	return (new_head);
}

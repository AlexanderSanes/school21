/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:30:35 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:20:55 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>

t_stack	*swap_top(t_stack *head)
{
	t_stack	*prev;
	t_stack	*next;

	prev = head->prev;
	next = head->next;
	if (head->next == prev)
		return (rotate_stack(head));
	prev->next = next;
	head->prev = next;
	head->next = next->next;
	next->prev = prev;
	next->next = head;
	return (next);
}

t_stack	*push_front(t_stack *head, int value)
{
	t_stack	*new;

	if (!head)
		return (init_stack(value));
	else
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->value = value;
		new->next = head;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
	}
	return (new);
}

t_stack	*pop_front(t_stack *head)
{
	t_stack	*prev;
	t_stack	*next;

	if (!head)
		return (NULL);
	if (head == head->next)
	{
		free(head);
		return (NULL);
	}
	next = head->next;
	prev = head->prev;
	prev->next = head->next;
	next->prev = head->prev;
	free(head);
	return (next);
}

t_stack	*rotate_stack(t_stack *head)
{
	if (!head)
		return (NULL);
	return (head->next);
}

t_stack	*reverse_rotate_stack(t_stack *head)
{
	if (!head)
		return (NULL);
	return (head->prev);
}

// void	print_stack(t_stack	*a, t_stack *b)
// {
// 	t_stack	*head;
// 	t_stack	*head_b;

// 	head = a;
// 	head_b = b;
// 	write(1, "---------\n", 10);
// 	if (!a)
// 	{
// 		write(1, "Empty stack A\n", 12);
// 		return ;
// 	}
// 	write(1, "  ", 2);
// 	ft_putnbr_fd(head->value, 1);
// 	write(1, "   ", 3);

// 	if (b)
// 	{
// 		ft_putnbr_fd(head_b->value, 1);
// 		head_b = head_b->next;
// 	}
// 	else
// 		write(1, " ", 1);
// 	write(1, "  \n", 3);
// 	head = head->next;
// 	while (head != a)
// 	{
// 		write(1, "  ", 2);
// 		ft_putnbr_fd(head->value, 1);
// 		write(1, "   ", 3);
// 		if (b)
// 		{
// 			if (head_b != b)
// 				ft_putnbr_fd(head_b->value, 1);
// 			head_b = head_b->next;
// 		}
// 		else
// 			write(1, " ", 1);
// 		write(1, "  \n", 3);
// 		head = head->next;
// 	}
// 	write(1, "--a---b--\n", 10);
// 	write(1, "---------\n", 10);

// }

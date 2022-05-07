/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:31:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 09:10:24 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}	t_stack;

t_stack	*init_stack(int a);
t_stack	*swap_top(t_stack *head);
t_stack	*push_front(t_stack *head, int value);
t_stack	*pop_front(t_stack *head);
t_stack	*rotate_stack(t_stack *head);
t_stack	*reverse_rotate_stack(t_stack *head);
void	print_stack(t_stack	*a, t_stack *b);
t_stack	*fill_stack(int *arr, int size);
int		is_sorted(t_stack *a);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sort_100(t_stack **a, t_stack **b);
void	sort_500(t_stack **a, t_stack **b);
int		max_index(t_stack *a);
int		min_index(t_stack *a);
int		is_more_on_left(t_stack *a, int index);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		cpa(t_stack **a, t_stack **b);
int		cpb(t_stack **a, t_stack **b);
int		csa(t_stack **a);
int		csb(t_stack **b);
int		css(t_stack **a, t_stack **b);
int		cra(t_stack **a);
int		crb(t_stack **b);
int		crr(t_stack **a, t_stack **b);
int		crra(t_stack **a);
int		crrb(t_stack **b);
int		crrr(t_stack **a, t_stack **b);

#endif
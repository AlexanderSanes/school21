/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:46:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 10:56:17 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

int		*init_array(char **argv, int n);
void	print_array(int *arr, int size);
int		check_args(char **args, int argc);
void	bubble_sort_array(int *arr, int size);
void	checker(t_stack **a, t_stack **b);
int		print_error(void);
void	free_stack(t_stack **a);
int		is_sorted(t_stack *a);
// char	**get_args(char **argv, int argc);
int		size_of_args(char **str);
int		free_arrstr(char **res);
int		dublicate_check(int *arr, int argc);

#endif
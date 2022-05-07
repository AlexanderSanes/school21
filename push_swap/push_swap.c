/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:09:09 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/17 11:49:23 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"
#include "libft.h"

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_2(a);
	if (size == 3)
		sort_3(a);
	if (size == 4)
		sort_4(a, b);
	if (size == 5)
		sort_5(a, b);
	if (size > 5 && size <= 100)
		sort_100(a, b);
	if (size > 100)
		sort_500(a, b);
}

int	parse_args1(char **argv, int **arr, int argc)
{
	int		size;

	size = argc - 1;
	if (!check_args(argv + 1, size))
		return (print_error());
	*arr = init_array(argv + size, size);
	if (!dublicate_check(*arr, size))
	{
		free(*arr);
		return (print_error());
	}
	return (size);
}

int	parse_args2(char **argv, int **arr)
{
	char	**args;
	int		size;

	args = ft_split(argv[1], ' ');
	if (!args)
		return (0);
	size = size_of_args(args);
	if (!check_args(args, size))
	{
		free_arrstr(args);
		return (print_error());
	}
	*arr = init_array(args + size - 1, size);
	if (!dublicate_check(*arr, size))
	{
		free_arrstr(args);
		free(*arr);
		return (print_error());
	}
	free_arrstr(args);
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		size;

	if (argc < 2)
		return (1);
	if (argc == 2)
		size = parse_args2(argv, &arr);
	else
		size = parse_args1(argv, &arr, argc);
	if (!size)
		return (1);
	a = fill_stack(arr, size);
	b = NULL;
	if (!is_sorted(a))
		sort(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	free(arr);
}

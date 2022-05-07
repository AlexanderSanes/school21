/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:17:31 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/17 11:49:29 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

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
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free(arr);
}

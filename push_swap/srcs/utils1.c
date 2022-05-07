/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:53:12 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/14 18:34:28 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "push_swap.h"

int	print_error(void)
{	
	write(2, "Error\n", 6);
	return (0);
}

int	size_of_args(char **str)
{
	int	size;

	size = 1;
	if (!str[0])
		return (0);
	while (str[size])
		size++;
	return (size);
}

int	*init_array(char **argv, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = ft_atoi(*argv--);
	return (arr);
}

// void	print_array(int *arr, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		ft_putnbr_fd(arr[i++], 1);
// 		write(1, " ", 1);
// 	}
// 	write(1, "\n", 1);
// }

// void	print_arrstr(char **args)
// {
// 	int	i;

// 	i = 0;
// 	while (args[i])
// 	{
// 		write(1, args[i], ft_strlen(args[i]));
// 		i++;
// 	}
// }

// char	**copy_argv(char **arr, int size)
// {
// 	char	**copy;
// 	int		i;

// 	i = 0;
// 	copy = malloc(sizeof(char *) * (size + 1));
// 	if (!copy)
// 		return (NULL);
// 	while (i < size)
// 	{
// 		copy[i] = malloc(sizeof(char) * (ft_strlen(arr[i])));
// 		if (!copy[i])
// 		{
// 			free_arrstr(copy);
// 			return (NULL);
// 		}
// 		ft_strlcpy(copy[i], arr[i], ft_strlen(arr[i]) + 1);
// 		i++;
// 		copy[i] = NULL;
// 	}
// 	return (copy);
// }

// char	**get_args(char **argv, int argc)
// {
// 	if (argc > 2)
// 		return (copy_argv(argv + 1, argc - 1));
// 	else
// 		return (ft_split(argv[1], ' '));
// }

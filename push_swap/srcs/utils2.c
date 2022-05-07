/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:25:28 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/17 11:47:42 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "push_swap.h"

int	dublicate_check(int *arr, int argc)
{
	int		*comp;
	int		i;
	int		k;

	i = 0;
	comp = malloc(sizeof(int *) * (argc + 1));
	if (!comp)
		return (0);
	while (i < argc)
	{
		k = 0;
		while (k < i)
		{
			if (comp[k++] == arr[i])
			{
				free(comp);
				return (0);
			}
		}
		comp[k] = arr[i];
		i++;
	}
	free(comp);
	return (1);
}

int	check_args(char **args, int argc)
{
	int	i;
	int	tmp;

	i = 0;
	if (argc == 0)
		return (0);
	while (i <= argc - 1)
	{
		if (ft_isnum(args[i]))
		{
			tmp = ft_atoi(args[i]);
			if (tmp < 0 && args[i][0] != '-')
				return (0);
			if (tmp > 0 && args[i][0] == '-')
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	free_arrstr(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:49:26 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/17 14:09:09 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define USAGE_MSG "./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n"

int	main(int argc, char **argv)
{
	t_philo_data	*data;

	data = malloc(sizeof(t_philo_data));
	data->required_eats = -1;
	if (argc > 6 || argc < 5)
	{
		printf(USAGE_MSG);
		return (1);
	}
	if (argc == 6)
		data->required_eats = atoi(argv[5]);
	data->num_of_philo = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->start_time = 0;
	data->died_flag = 0;
	start_life(data);
	return (0);
}

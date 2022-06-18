/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:41:56 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/14 13:58:18 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo_data *data)
{
	int	i;

	i = 0;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	while (i < data->num_of_philo)
		pthread_mutex_init(&data->fork_mutex[i++], NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->died_mutex, NULL);
}

void	destroy_mutex(t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
		pthread_mutex_destroy(&data->fork_mutex[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->died_mutex);
}

void	init_philos(t_philo *philo, t_philo_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].last_feeding = get_time(data);
		philo[i].left_fork_id = i;
		philo[i].right_fork_id = (i + 1) % data->num_of_philo;
		philo[i].food_counter = 0;
		philo[i].data = data;
		i++;
	}
}

void	exit_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
		pthread_detach(philo[i++].philo_id);
	destroy_mutex(philo->data);
	free(philo->data->fork_mutex);
	free(philo->data);
	free(philo);
}

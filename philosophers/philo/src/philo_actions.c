/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:31:01 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/14 12:44:03 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(t_philo_data *data)
{
	t_timeval	tmp_time;
	time_t		time;

	gettimeofday(&tmp_time, NULL);
	time = (tmp_time.tv_sec * 1000 + tmp_time.tv_usec / 1000);
	return (time - data->start_time);
}

void	philo_action(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->died_flag)
		printf("%ld %d %s\n", get_time(philo->data), \
		(philo->left_fork_id % philo->data->num_of_philo) + 1, message);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

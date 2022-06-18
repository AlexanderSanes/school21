/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:31:01 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/19 20:04:04 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(philo->data->print_sem);
	if (!philo->data->died_flag)
		printf("%ld %d %s\n", get_time(philo->data), \
		(philo->philo_num), message);
	sem_post(philo->data->print_sem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanes <sanes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:52:44 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/03 22:16:47 by sanes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_a_while(t_philo_data *data, time_t time)
{
	time_t	current_time;

	current_time = get_time(data);
	while (!data->died_flag)
	{
		if (get_time(data) - current_time >= time)
			return ;
		usleep(50);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died_mutex);
	philo_action(philo, EAT_MSG);
	philo->last_feeding = get_time(philo->data);
	pthread_mutex_unlock(&philo->data->died_mutex);
	wait_for_a_while(philo->data, philo->data->time_to_eat);
	philo->food_counter++;
}

static void	*philo_life(void *arg)
{
	t_philo		*philo;

	philo = arg;
	if (philo->left_fork_id % 2)
		usleep(1000);
	while (!philo->data->died_flag)
	{
		pthread_mutex_lock(&philo->data->fork_mutex[philo->left_fork_id]);
		philo_action(philo, FORK_MSG);
		pthread_mutex_lock(&philo->data->fork_mutex[philo->right_fork_id]);
		philo_action(philo, FORK_MSG);
		eating(philo);
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->left_fork_id]);
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->right_fork_id]);
		if (philo->data->all_stuffed_flag)
			return (NULL);
		philo_action(philo, SLEEP_MSG);
		wait_for_a_while(philo->data, philo->data->time_to_sleep);
		philo_action(philo, THINK_MSG);
	}
	return (NULL);
}

static void	check_end(t_philo *philo, t_philo_data *data)
{
	int				i;

	while (!data->all_stuffed_flag)
	{
		i = -1;
		while (++i < data->num_of_philo && !data->died_flag)
		{
			pthread_mutex_lock(&data->died_mutex);
			if (get_time(data) - philo[i].last_feeding > data->time_to_die)
			{
				philo_action(philo, DIE_MSG);
				data->died_flag = 1;
			}
			pthread_mutex_unlock(&data->died_mutex);
			usleep(100);
		}
		if (data->died_flag)
			return ;
		i = 0;
		while (data->required_eats != -1 && i < data->num_of_philo \
			&& philo[i].food_counter >= data->required_eats)
			i++;
		if (i == data->num_of_philo)
			data->all_stuffed_flag = 1;
	}
}

void	start_life(t_philo_data *data)
{
	int				i;
	t_philo			*philo;

	philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data->start_time = get_time(data);
	init_philos(philo, data);
	init_mutex(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_create(&philo[i].philo_id, NULL, philo_life, &philo[i]);
		i++;
	}
	check_end(philo, data);
	exit_philo(philo);
}

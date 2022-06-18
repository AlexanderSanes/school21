/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanes <sanes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:52:44 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/03 22:27:25 by sanes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(philo->data->forks_sem);
	philo_action(philo, FORK_MSG);
	sem_wait(philo->data->forks_sem);
	philo_action(philo, FORK_MSG);
	sem_wait(philo->data->died_sem);
	philo_action(philo, EAT_MSG);
	philo->last_feeding = get_time(philo->data);
	sem_post(philo->data->died_sem);
	wait_for_a_while(philo->data, philo->data->time_to_eat);
	philo->food_counter++;
	sem_post(philo->data->forks_sem);
	sem_post(philo->data->forks_sem);
}

static void	*check_end(void *arg)
{
	t_philo			*philo;
	t_philo_data	*data;

	philo = arg;
	data = philo->data;
	while (1)
	{
		sem_wait(data->died_sem);
		if (get_time(data) - philo->last_feeding > data->time_to_die)
		{
			philo_action(philo, DIE_MSG);
			data->died_flag = 1;
			sem_wait(data->print_sem);
			exit(1);
		}
		sem_post(data->died_sem);
		if (data->died_flag)
			return (NULL);
		usleep(100);
		if (data->required_eats != -1 && \
			philo->food_counter >= data->required_eats)
			return (NULL);
	}
	return (NULL);
}

static void	philo_life(void *arg)
{
	t_philo		*philo;

	philo = arg;
	pthread_create(&philo->thread_id, NULL, check_end, arg);
	if (philo->philo_num % 2 == 0)
		usleep(1000);
	while (!philo->data->died_flag)
	{
		eating(philo);
		if (philo->data->required_eats != -1 && \
			philo->food_counter >= philo->data->required_eats)
			break ;
		philo_action(philo, SLEEP_MSG);
		wait_for_a_while(philo->data, philo->data->time_to_sleep);
		philo_action(philo, THINK_MSG);
	}
	pthread_join(philo->thread_id, NULL);
	if (philo->data->died_flag)
		exit(1);
	exit(0);
}

void	start_life(t_philo_data *data)
{
	int				i;
	t_philo			*philo;

	philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data->start_time = get_time(data);
	init_philos(philo, data);
	init_sem(data);
	i = -1;
	while (++i < data->num_of_philo)
	{
		philo[i].process_id = fork();
		if (philo[i].process_id == 0)
			philo_life(&philo[i]);
		usleep(100);
	}
	exit_philo(philo);
}

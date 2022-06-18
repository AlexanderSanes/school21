/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:41:56 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/19 20:18:08 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_philo_data *data)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
	data->forks_sem = sem_open("forks", O_CREAT, S_IRWXU, data->num_of_philo);
	data->print_sem = sem_open("print", O_CREAT, S_IRWXU, 1);
	data->died_sem = sem_open("death", O_CREAT, S_IRWXU, 1);
}

void	destroy_sem(t_philo_data *data)
{
	sem_close(data->forks_sem);
	sem_close(data->print_sem);
	sem_close(data->died_sem);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
}

void	init_philos(t_philo *philo, t_philo_data *data)
{
	int		i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		philo[i].last_feeding = get_time(data);
		philo[i].philo_num = i + 1;
		philo[i].food_counter = 0;
		philo[i].data = data;
	}
}

void	exit_philo(t_philo *philo)
{
	int	i;
	int	wpid;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		waitpid(-1, &wpid, 0);
		if (wpid != 0)
		{
			i = -1;
			while (++i < philo->data->num_of_philo)
				kill(philo[i].process_id, SIGTERM);
		}
		i++;
	}
	destroy_sem(philo->data);
	free(philo->data);
	free(philo);
}

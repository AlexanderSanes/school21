/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by rdeanne           #+#    #+#             */
/*   Updated: 2022/05/19 20:18:05 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>	//write()
# include <stdio.h>		//printf()
# include <stdlib.h>	//atoi()
# include <sys/time.h>	//gettimeofday()
# include <string.h>	//memset()
# include <pthread.h>	//pthreads
# include <fcntl.h> 		
# include <semaphore.h>	//semaphores
# include <signal.h>		//kill
# include <sys/types.h>	//
# include <sys/wait.h>	//waitpid

# define SLEEP_MSG "is sleeping"
# define EAT_MSG "is eating"
# define THINK_MSG "is thinking"
# define FORK_MSG "has taken a fork"
# define DIE_MSG "died"

typedef struct timeval	t_timeval;

typedef struct s_philo_data
{
	int				required_eats;
	int				num_of_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	sem_t			*forks_sem;
	sem_t			*print_sem;
	sem_t			*died_sem;
	int				died_flag;
}	t_philo_data;

typedef struct s_philo
{
	int				philo_num;
	int				food_counter;
	time_t			last_feeding;
	pthread_t		thread_id;
	pid_t			process_id;
	t_philo_data	*data;
}	t_philo;

void	start_life(t_philo_data *data);
void	philo_action(t_philo *philo, char *message);

time_t	get_time(t_philo_data *data);
void	init_sem(t_philo_data *data);
void	destroy_sem(t_philo_data *data);
void	init_philos(t_philo *philo, t_philo_data *data);
void	exit_philo(t_philo *philo);

/* External funcions
	free,					write,
	memset,					printf,					malloc,
	usleep,					gettimeofday,			pthread_create,
	pthread_detach,			pthread_join,			pthread_mutex_init,
	pthread_mutex_destroy,	pthread_mutex_lock,		pthread_mutex_unlock
*/

#endif
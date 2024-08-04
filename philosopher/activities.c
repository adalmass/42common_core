/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/04 22:25:34 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fonction_qui_gere_la_mort(void *infos)
{
	long	last_meal;
	long	current_time;

	t_infos *inf = (t_infos *) infos;

	last_meal = inf->last_time_eat;
	gettimeofday(&inf->time, NULL);
	current_time = inf->time.tv_usec / 1000;
	if (last_meal != current_time)
	{
		printf("lastmeal - current_time: %ld - %ld\n", last_meal, current_time);
		if (last_meal < current_time)
		{
			current_time = (current_time - last_meal);
			printf("philo %d last meal < : %ld\n", inf->phi_id, current_time);
		}
		else if (last_meal > current_time)
		{
			current_time = (last_meal - current_time);
			printf("philo %d last meal > : %ld\n", inf->phi_id, current_time);
		}
	}
	//i = inf->time.tv_sec;
	//printf(" Philo %d lastmeal  : %ld,%ld\n", inf->phi_id,i, last_meal);
	//printf("SALOPE: %ld\n", inf->last_time_eat);
	//printf("temps: %ld\n", inf->timer_eat.tv_usec / 1000);
	//printf("temps: %ld\n", inf->time.tv_usec / 1000);
}

void    *try_activity(void *infos)
{
	t_infos *inf = (t_infos *) infos;

	if (inf->eat_count != inf->eat_max)
		eating(inf);
	if (inf->stop_eat == 1)
		return (NULL);
	thinking(inf);
	sleeping(inf);
	return (NULL);
}

void    eating(t_infos *inf)
{
	if (inf->phi_nb % 2 != 0 && inf->phi_id % 2 != 0)
		usleep(100);
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	printf(GREEN"Philo %d is eating\n"RESET, inf->phi_id);
	gettimeofday(&inf->time, NULL);
	inf->last_time_eat = inf->time.tv_usec / 1000;
	printf("Philo %d actualmeal: %ld,%ld\n", inf->phi_id, inf->time.tv_sec, inf->last_time_eat);
	usleep(inf->t_eating);
	inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->eat_count == inf->eat_max)
		inf->stop_eat = 1;
}

void	thinking(t_infos *inf)
{
	printf(YELLOW"Philo %d is thinking\n"RESET, inf->phi_id);
}

void	sleeping(t_infos *inf)
{
	printf(CYAN"Philo %d is sleeping\n"RESET, inf->phi_id);
	usleep(inf->t_sleeping);
}

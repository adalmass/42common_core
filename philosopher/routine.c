/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/09 16:26:49 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fonction_qui_gere_la_mort(void *infos)
{
	int		i;
	long	time;

	t_infos *inf = (t_infos *) infos;
	while (1)
	{
		i = 0;
		time = print_time(inf) - inf->last_time_eat;
		//printf("TIME: %ld - DYING: %d\n", time, inf->t_dying / 1000);
		while (i < inf[i].phi_nb)
		{
			if (inf->last_time_eat > inf[i].t_dying / 1000)
			{
				printf(RED "%ld PHILO %d IS DEAD\n" RESET, inf->last_time_eat, inf[i].phi_id);
				i = 0;
				while (i < inf[i].phi_nb)
				{
					inf[i].stop_simulation = 1;
					i++;
				}
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void    *routine(void *infos)
{
	t_infos *inf = (t_infos *) infos;

	while (1)
	{
		if (inf->stop_simulation)
			break ;
		if (!inf->stop_eat)
			eating(inf);
		if (inf->stop_eat == 1)
			break ;
		if (inf->stop_simulation)
			break ;
		sleeping(inf);
		if (inf->stop_simulation)
			break ;
		thinking(inf);
	}
	return (NULL);
}

void	eating(t_infos *inf)
{
	long	time;

	// if (inf->phi_nb % 2 == 0 && inf->phi_id % 2 == 0)
	// 	usleep(150);
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	time = print_time(inf) - inf->start_time;
	if (inf->stop_simulation)
		return ;
	printf(GREEN"%ld Philo %d is eating\n"RESET, time, inf->phi_id);
	usleep(inf->t_eating);
	inf->last_time_eat = print_time(inf);
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->eat_max && inf->eat_count == inf->eat_max)
		inf->stop_eat = 1;
	return;
}

void	thinking(t_infos *inf)
{
	long	time;

	time = print_time(inf) - inf->start_time;
	if (inf->stop_simulation)
		return ;
	printf(YELLOW"%ld Philo %d is thinking\n"RESET, time, inf->phi_id);
	return ;
}

void	sleeping(t_infos *inf)
{
	long	time;

	time = print_time(inf) - inf->start_time;
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is sleeping\n"RESET, time, inf->phi_id);
	usleep(inf->t_sleeping);
	return ;
}

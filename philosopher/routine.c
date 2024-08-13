/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/13 23:43:25 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usleep_remake(t_infos *inf, long sleep)
{
	long	time;
	long	start_time;

	gettimeofday(&inf->time, NULL);
	start_time = inf->time.tv_sec * 1000000 + inf->time.tv_usec;
	while (1)
	{
		gettimeofday(&inf->time, NULL);
		time = inf->time.tv_sec * 1000000 + inf->time.tv_usec;
		if ((time - start_time) >= sleep)
			break ;
		usleep(25);
	}
}

void	*fonction_qui_gere_la_mort(void *infos)
{
	int		i;
	long	time;
	t_infos	*inf = (t_infos *) infos;

	while (1)
	{
		i = 0;
		while (i < inf[i].phi_nb)
		{
			if (inf->last_time_eat > 0)
			{
				time = print_time(inf);
				//printf("TIME: %ld - LAST EAT: %ld\nRESULT: %ld\n", time, inf->last_time_eat, time - inf->last_time_eat);
				if ((time - inf->last_time_eat)  > inf[i].t_dying / 1000)
				{
					printf(RED "%ld PHILO %d IS DEAD\n" RESET, (time - inf->last_time_eat), inf[i].phi_id);
					i = 0;
					while (i < inf[i].phi_nb)
					{
						inf[i].stop_simulation = 1;
						i++;
					}
					return (NULL);
				}
			}
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *infos)
{
	t_infos *inf = (t_infos *) infos;
	if (inf->phi_nb == 1)
	{
		printf("0 PHILO %d is taking fork 1\n", inf[0].phi_id);
		usleep_remake(inf, inf->t_dying);
		printf(RED "%d PHILO %d IS DEAD\n" RESET, inf->t_dying / 1000, inf[0].phi_id);
		inf->stop_simulation = 1;
		return (NULL);
	}
	if (inf->phi_nb % 2 == 0 && inf->phi_id % 2 == 0)
		usleep(50);
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

	time = print_time(inf) - inf->start_time;
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is taking fork 1\n"RESET, time, inf->phi_id);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is taking fork 2\n"RESET, time, inf->phi_id);
	printf(GREEN"%ld Philo %d is eating\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_eating);
	inf->last_time_eat = print_time(inf);
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	if (inf->stop_simulation)
		return ;
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->stop_simulation)
		return ;
	if (inf->eat_max && inf->eat_count == inf->eat_max)
		inf->stop_eat = 1;
	return ;
}

void	thinking(t_infos *inf)
{
	long	time;

	if (inf->stop_simulation)
		return ;
	time = print_time(inf) - inf->start_time;
	printf(YELLOW"%ld Philo %d is thinking\n"RESET, time, inf->phi_id);
	return ;
}

void	sleeping(t_infos *inf)
{
	long	time;

	if (inf->stop_simulation)
		return ;
	time = print_time(inf) - inf->start_time;
	printf(CYAN"%ld Philo %d is sleeping\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_sleeping);
	return ;
}

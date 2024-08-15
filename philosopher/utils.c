/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/15 11:08:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *msg)
{
	printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}

void	destroy_mutex(t_ph *phi)
{
	int	y;

	y = 0;
	while (phi->infos[y].fork)
	{
		pthread_mutex_destroy(phi->infos[y].fork);
		y++;
	}
	printf("destroy mutex ok\n");
}

void	join_threads(t_ph *phi, pthread_t *philo)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}

void	init_mutex(t_ph *phi, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

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
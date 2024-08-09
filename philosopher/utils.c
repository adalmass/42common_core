/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/09 16:20:06 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *msg)
{
	printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}

long	get_time(t_infos *inf)
{
	long	current_time;

	gettimeofday(&inf->time, NULL);
	current_time = (inf->time.tv_sec * 1000000) + inf->time.tv_usec;
	return (current_time);
}

void	destroy_mutex(t_ph *phi)
{
	int	x;
	int	y;

	y = 0;
	while (phi->infos[y].fork)
	{
		x = 0;
		while (phi[y].infos[y].fork)
		{
			pthread_mutex_destroy(&phi[y].infos[y].fork);
			x++;
		}
		y++;
	}
	printf("destroy mutex ok\n");
}

void	join_threads(t_ph *phi, pthread_t *philo, pthread_t *observe)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_join(philo[i], NULL);
		//pthread_join(observe[i], NULL);
		i++;
	}
}

void	init_mutex(t_ph *phi, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	//pthread_mutex_init(&phi->infos->print, NULL); 
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

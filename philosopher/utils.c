/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/24 22:29:11 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *msg)
{
	printf(YELLOW "PHILO ERROR: %s\n" RST, msg);
}

void	destroy_mutex(t_ph *phi)
{
	int	y;

	y = 0;
	pthread_mutex_destroy(&phi->check_stop);
	pthread_mutex_destroy(&phi->print);
	while (y < phi->phi_nb)
	{
		pthread_mutex_destroy(&phi->infos[y].check_eat);
		pthread_mutex_destroy(&phi->infos[y].check_l_meal);
		y++;
	}
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
	long	result;

	gettimeofday(&inf->time, NULL);
	start_time = (inf->time.tv_sec * 1000000) + inf->time.tv_usec;
	result = 0;
	while (result <= sleep)
	{
		if (check_stop(inf))
			return ;
		gettimeofday(&inf->time, NULL);
		time = (inf->time.tv_sec * 1000000) + inf->time.tv_usec;
		if (check_stop(inf))
			return ;
		result = time - start_time;
		usleep(25);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/11 23:07:13 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *msg)
{
	printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}

// void	destroy_mutex(t_ph *phi)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (phi->infos[y].fork)
// 	{
// 		x = 0;
// 		while (phi[y].infos[y].fork)
// 		{
// 			pthread_mutex_destroy(&phi[y]->infos->fork);
// 			x++;
// 		}
// 		y++;
// 	}
// 	printf("destroy mutex ok\n");
//}

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
	//pthread_mutex_init(&phi->infos->print, NULL); 
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

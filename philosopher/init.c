/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:44 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/25 01:34:11 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_ph *phi, t_infos *inf, char **av)
{
	phi->phi_nb = ft_atoi(av[1]);
	inf->t_dying = ft_atoi(av[2]);
	inf->t_eating = ft_atoi(av[3]);
	inf->t_sleeping = ft_atoi(av[4]);
	if (av[5])
		inf->eat_counter = ft_atoi(av[5]);
	else
		inf->eat_counter = 0;
	phi->phi = malloc(sizeof(pthread_t *) * (phi->phi_nb));
	if (!phi->phi)
	{
		error_found("phi->phi malloc failed");
		return (0);
	}
	phi->forks = malloc(sizeof(pthread_t *) * (phi->phi_nb));
	if (!phi->forks)
	{
		error_found("phi->fork malloc failed");
		return (0);
	}
	return (1);
}

void	create_phi(t_ph *phi)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_create(&phi->phi[i], NULL,
			(void *)try_activity, (t_ph *)phi);
		i++;
	}
}

void	create_fork(t_ph *phi)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&phi->forks[i], NULL);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:44 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/28 20:22:42 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_ph *phi, t_infos *inf, char **av)
{
	(void)inf;
	if (!init_phi(phi, av))
		return (0);
	init_infos(phi, av);
	return (1);
}

int	init_phi(t_ph *phi, char **av)
{
	phi->phi_nb = ft_atoi(av[1]);
	phi->infos = malloc(sizeof(t_infos) * phi->phi_nb);
	phi->phi = malloc(sizeof(pthread_t *) * (phi->phi_nb));
	if (!phi->phi)
	{
		error_found("phi->phi malloc failed");
		return (0);
	}
	return (1);
}

void	init_infos(t_ph *phi, char **av)
{
	phi->infos->t_dying = ft_atoi(av[2]);
	phi->infos->t_eating = ft_atoi(av[3]);
	phi->infos->t_sleeping = ft_atoi(av[4]);
	if (av[5])
		phi->infos->eat_counter = ft_atoi(av[5]);
	else
		phi->infos->eat_counter = 0;
	phi->infos->phi_id = 0;
	phi->infos->phi = malloc(sizeof(t_ph));
	phi->infos->phi->phi_nb = ft_atoi(av[1]);
	phi->infos->phi->phi = malloc(sizeof(pthread_t *) * ft_atoi(av[1] + 1));
	phi->infos->phi->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
}

void	create_mutex(t_ph *phi)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&phi->infos->phi->forks[i], NULL);
		i++;
	}
}

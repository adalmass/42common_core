/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:44 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/27 22:12:47 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_ph *phi, t_infos *inf, char **av)
{
	init_phi(t_ph *phi);
	init_infos(t_infos inf);
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
	phi->forks = malloc(sizeof(pthread_mutex_t *) * (phi->phi_nb));
	if (!phi->forks)
	{
		error_found("phi->fork malloc failed");
		return (0);
	}
}

int	init_infos(t_infos *inf, char **av)
{
	inf->t_dying = ft_atoi(av[2]);
	inf->t_eating = ft_atoi(av[3]);
	inf->t_sleeping = ft_atoi(av[4]);
	if (av[5])
		inf->eat_counter = ft_atoi(av[5]);
	else
		inf->eat_counter = 0;
	inf->phi_id = 0;
	return (1);
}

void	create_phi(t_ph *phi)
{
	int	i;

	i = 0;
	//write(1, "ok\n", 3);
	//phi->infos[0] = malloc(sizeof(t_infos));
	phi->infos->phi_id = i;
	printf("ICI Philo %d is eating\n", phi->infos->phi_id);
	pthread_mutex_init(&phi->forks[0], NULL);
	pthread_create(&phi->phi[0], NULL, (void *)try_activity, (void *)&phi->infos[0]);
	pthread_join(phi->phi[0], NULL);
	i++;
	pthread_mutex_destroy(&phi->forks[0]);	
	return ;

	// while (i < phi->phi_nb)
	// {
	// 	phi->infos[i] = (t_infos)malloc(sizeof(t_infos));
	// 	phi->infos[i]->phi_id = i + 1;
	// 	pthread_create(&phi->phi[i], NULL, (void *)try_activity, (void *)&phi->infos[i]);
	// 	i++;
	// }
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

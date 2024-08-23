/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:44 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/23 18:20:37 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	p_time(t_infos *inf)
{
	long	time;

	time = get_time(inf) - inf->start_time;
	return (time);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	init_phi(t_ph *phi, char **av)
{
	phi->t_dying = ft_atoi(av[2]) * 1000;
	phi->t_eating = ft_atoi(av[3]) * 1000;
	phi->t_sleeping = ft_atoi(av[4]) * 1000;
	if (av[5])
		phi->eat_max = ft_atoi(av[5]);
	else
		phi->eat_max = 0;
	phi->phi_nb = ft_atoi(av[1]);
	phi->infos = malloc(sizeof(t_infos) * phi->phi_nb);
	if (!phi->infos)
	{
		error_found("phi->infos malloc failed");
		return (0);
	}
	phi->infos->meal_finished = 0;
	phi->stop_simulation = 0;
	pthread_mutex_init(&phi->check_stop, NULL);
	pthread_mutex_init(&phi->print, NULL);
	return (1);
}

void	init_infos2(t_ph *phi, int i)
{
	phi->infos[i].phi_id = i + 1;
	phi->infos[i].stop_eat = 0;
	phi->infos[i].eat_count = 0;
	phi->infos[i].is_dead = 0;
	phi->infos[i].ph = phi;
}

void	init_infos(t_ph *phi, pthread_mutex_t *forks, long time)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		init_infos2(phi, i);
		phi->infos[i].start_time = time;
		phi->infos[i].phi_nb = phi->phi_nb;
		phi->infos[i].t_dying = phi->t_dying;
		phi->infos[i].t_eating = phi->t_eating;
		phi->infos[i].t_sleeping = phi->t_sleeping;
		pthread_mutex_init(&phi->infos[i].check_l_meal, NULL);
		pthread_mutex_init(&phi->infos[i].check_eat, NULL);
		phi->infos[i].eat_max = phi->eat_max;
		if (phi->infos[i].phi_id == phi->infos[i].phi_nb)
			phi->infos[i].right_fork = 0;
		else
			phi->infos[i].right_fork = phi->infos[i].phi_id;
		phi->infos[i].left_fork = phi->infos[i].phi_id - 1;
		phi->infos[i].last_meal = phi->infos->last_meal;
		phi->infos[i].fork = forks;
		i++;
	}
}

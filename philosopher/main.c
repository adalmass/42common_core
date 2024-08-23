/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/23 17:31:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char *arg)
{
	int	x;

	x = 0;
	if (!handle_int_limit(arg))
		return (0);
	while (arg[x])
	{
		if (!ft_isdigit(arg[x]))
		{
			error_found("args must be positives digits");
			return (0);
		}
		x++;
	}
	if (ft_atoi(arg) == 0)
	{
		error_found("arg can't be 0");
		return (0);
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	int	y;

	y = 1;
	if (ac > 6)
	{
		error_found("too many arguments (max 5)");
		return (0);
	}
	if (ac < 5)
	{
		error_found("too few arguments (min 4)");
		return (0);
	}
	if (ft_atoi(av[1]) <= 0)
	{
		error_found("we need at leat one phisopher");
		return (0);
	}
	while (av[y])
	{
		if (!check_arg(av[y]))
			return (0);
		y++;
	}
	return (1);
}

long	get_time(t_infos *inf)
{
	long	time;

	gettimeofday(&inf->time, NULL);
	time = (inf->time.tv_sec * 1000) + (inf->time.tv_usec / 1000);
	return (time);
}

void	start_simulation(t_ph *phi)
{
	int				i;
	long			time;
	pthread_t		*philo;
	pthread_t		observe;
	pthread_mutex_t	*forks;

	philo = malloc(sizeof(pthread_t) * phi->phi_nb);
	forks = malloc(sizeof(pthread_mutex_t) * phi->phi_nb);
	init_mutex(phi, forks);
	time = get_time(phi->infos);
	phi->infos->last_meal = 0;
	init_infos(phi, forks, time);
	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_create(&philo[i], NULL, (void *)rout, (void *)&phi->infos[i]);
		i++;
	}
	pthread_create(&observe, NULL, (void *)handle_death, (void *)phi->infos);
	join_threads(phi, philo);
	pthread_join(observe, NULL);
	destroy_mutex(phi);
	free (phi->infos);
	free (philo);
	free (forks);
}

int	main(int ac, char **av)
{
	t_ph	phi;

	if (!parsing(ac, av))
		return (1);
	if (!init_phi(&phi, av))
		return (1);
	start_simulation(&phi);
}

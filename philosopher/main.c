/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/13 21:54:11 by aldalmas         ###   ########.fr       */
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
		if (arg[x] == '-')
			x++;
		if (!ft_isdigit(arg[x]))
		{
			error_found("args must be digits");
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

void	ft_exit(t_ph *phi)
{
	free (phi->infos);
	//destroy_mutex(phi);
	
}

long	print_time(t_infos *inf)
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

	i = 0;
	philo = malloc(sizeof(pthread_t) * phi->phi_nb);
	forks = malloc(sizeof(pthread_mutex_t) * phi->phi_nb);
	init_mutex(phi, forks);
	time = print_time(phi->infos);
	init_infos(phi, forks, time);
	while (i < phi->phi_nb)
	{
		pthread_create(&philo[i], NULL, (void *)routine, (void *)&phi->infos[i]);
		i++;
	}
	pthread_create(&observe, NULL, (void *)fonction_qui_gere_la_mort, (void *)phi->infos);
	join_threads(phi, philo);
	i = 0;
	if (phi->infos[i].is_dead)
	{
		while (phi->phi_nb)
		{
			free (&phi->infos[i]);
			free (&philo[i]);
			i++;
		}
		free (phi->infos);
		free (philo);
		//free (forks);
		//ft_exit(phi);
	//destroy_mutex(phi);
	}
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

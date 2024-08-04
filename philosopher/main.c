/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/04 22:13:15 by aldalmas         ###   ########.fr       */
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

void	start_simulation(t_ph *phi)
{
	int				i;
	pthread_t		*philo;
	pthread_t		*observe;
	pthread_mutex_t	*forks;

	i = 0;
	philo = malloc(sizeof(pthread_t) * phi->phi_nb);
	forks = malloc(sizeof(pthread_mutex_t) * phi->phi_nb);
	observe = malloc(sizeof(pthread_t) * phi->phi_nb);
	while (i < phi->phi_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < phi->phi_nb)
	{
		init_infos(phi, i);
		phi->infos[i].fork = forks;
		pthread_create(&philo[i], NULL, (void *)try_activity, (void *)&phi->infos[i]);
		pthread_create(&observe[i], NULL, (void *)fonction_qui_gere_la_mort, (void *)&phi->infos[i]);
		i++;
	}
	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_join(philo[i], NULL);
		pthread_join(observe[i], NULL);
		i++;
	}
	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_mutex_destroy(&phi->infos->fork[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_ph     	phi;
	//struct timeval time;

	if (!parsing(ac, av))
		return (1);
	if (!init_phi(&phi, av))
		return (1);
	while (1)
	{
		start_simulation(&phi);
		if (phi.infos->stop_eat == 1)
			return (0); 
	}
	// print_time(&time);
	// usleep(1001200);
	// print_time(&time);
	//count_eating_time(phi.infos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/28 20:43:18 by aldalmas         ###   ########.fr       */
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

void	create_threads(t_ph *phi)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		printf(RED "boucle %d\n" RESET, i + 1);
		//phi->infos[i] = (t_ph)malloc(sizeof(t_ph));
		phi->infos->phi_id = i + 1;
		pthread_create(&phi->phi[i], NULL, (void *)try_activity, (void *)&phi->infos[i]);
		pthread_join(phi->phi[i], NULL);
		i++;
	}
}

void	destroy_mutex(t_ph *phi)
{
	int	i;

	i = 0;
	while (i < phi->phi_nb)
	{
		pthread_mutex_destroy(&phi->infos->phi->forks[i]);
		i++;
	}
}

void	start_simulation(t_ph *phi)
{
	create_mutex(phi);
	create_threads(phi);
}

int	main(int ac, char **av)
{
	t_ph     	phi;
	t_infos		inf;
	//struct timeval time;

	if (!parsing(ac, av))
		return (1);
	if (!init_struct(&phi, &inf, av))
		return (1);
	start_simulation(&phi);
	//create_fork(&phi);
	// print_time(&time);
	// usleep(1000000);
	// print_time(&time);
}

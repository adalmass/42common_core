/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:25:19 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/16 23:31:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop_simu(t_infos *inf, long time)
{
	int	i;

	pthread_mutex_lock(&inf->print);
	i = 0;
	printf(RED "%ld PHILO %d IS DEAD\n" RESET, time, inf[i].phi_id);
	while (i < inf->phi_nb)
	{
		pthread_mutex_lock(&inf[i].check_stop);
		inf[i].stop_simulation = 1;
		pthread_mutex_unlock(&inf[i].check_stop);
		i++;
	}
	pthread_mutex_unlock(&inf->print);
}

int	check_if_dead(t_infos *inf, int i)
{
	long	time;

	pthread_mutex_lock(&inf[i].check_l_meal);
	if (inf[i].last_meal != 0)
	{
		time = print_time(inf);
		if ((time - inf[i].last_meal) > inf[i].t_dying / 1000)
		{
			set_stop_simu(inf, time - inf->start_time);
			pthread_mutex_unlock(&inf[i].check_l_meal);
			return (1);
		}
	}
	pthread_mutex_unlock(&inf[i].check_l_meal);
	return (0);
}

void	*handle_death(void *infos)
{
	int		i;
	t_infos	*inf;

	inf = (t_infos *) infos;
	while (1)
	{
		i = 0;
		while (i < inf->phi_nb)
		{
			pthread_mutex_lock(&inf[i].check_eat);
			if (inf[i].stop_eat == 0)
			{
				pthread_mutex_unlock(&inf[i].check_eat);
				if (check_if_dead(inf, i))
					return (NULL);
			}
			else
			{
				pthread_mutex_unlock(&inf[i].check_eat);
				break ;
			}
			i++;
		}
	}
	return (NULL);
}

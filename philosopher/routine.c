/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/15 20:41:58 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop_simu(t_infos *inf, long time)
{
	int		i;
	long	norme;

	pthread_mutex_lock(&inf->print);
	i = 0;
	norme = inf[i].last_meal;
	printf(RED "%ld PHILO %d IS DEAD\n" RESET, (time - norme), inf[i].phi_id);
	while (i < inf[i].phi_nb)
	{
		inf[i].stop_simulation = 1;
		//printf("CACA: %p\n", &inf[i].phi_nb);
		i++;
	}
	pthread_mutex_unlock(&inf->print);
	destroy_print_mutex(inf);
}

void	*fonction_qui_gere_la_mort(void *infos)
{
	int		i;
	long	time;
	t_infos	*inf = (t_infos *) infos;

	init_write_mutex(inf);
	while (1)
	{
		i = 0;
		while (i < inf[i].phi_nb)
		{
			//printf("philo number: %d\n", inf[i].phi_nb);
			if (inf[i].last_meal > 0)
			{
				time = print_time(inf);
				if ((time - inf[i].last_meal) > inf[i].t_dying / 1000)
				{
					set_stop_simu(inf, time);
					return (NULL);
				}
			}
			i++;
		}
	}
	return (NULL);
}

void	handle_solo_philo(t_infos *inf)
{
	long	norme;
	long	norme_id;

	printf(CYAN"0 PHILO %d is taking fork 1\n"RESET, inf[0].phi_id);
	usleep_remake(inf, inf->t_dying);
	norme = inf->t_dying;
	norme_id = inf[0].phi_id;
	printf(RED "%ld PHILO %ld IS DEAD\n" RESET, norme / 1000, norme_id);
	inf->stop_simulation = 1;
}

void	*routine(void *infos)
{
	t_infos	*inf = (t_infos *) infos;

	if (inf->phi_nb == 1)
	{
		handle_solo_philo(inf);
		return (NULL);
	}
	if (inf->phi_id % 2 == 0)
		usleep(inf->t_eating);
	while (1)
	{
		if (inf->stop_simulation)
			break ;
		if (!inf->stop_eat)
			eating(inf);
		if (inf->stop_eat == 1 || inf->stop_simulation)
			break ;
		sleeping(inf);
		if (inf->stop_simulation)
			break ;
		thinking(inf);
	}
	return (NULL);
}

void	eating(t_infos *inf)
{
	long	time;

	time = print_time(inf) - inf->start_time;
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is taking fork 1\n"RESET, time, inf->phi_id);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is taking fork 2\n"RESET, time, inf->phi_id);
	if (inf->stop_simulation)
		return ;
	printf(GREEN"%ld Philo %d is eating\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_eating);
	inf->last_meal = print_time(inf);
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	if (inf->stop_simulation)
		return ;
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->stop_simulation)
		return ;
	if (inf->eat_max && inf->eat_count == inf->eat_max)
		inf->stop_eat = 1;
	return ;
}

void	thinking(t_infos *inf)
{
	long	time;

	if (inf->stop_simulation)
		return ;
	time = print_time(inf) - inf->start_time;
	if (inf->stop_simulation)
		return ;
	printf(YELLOW"%ld Philo %d is thinking\n"RESET, time, inf->phi_id);
	return ;
}

void	sleeping(t_infos *inf)
{
	long	time;

	if (inf->stop_simulation)
		return ;
	time = print_time(inf) - inf->start_time;
	if (inf->stop_simulation)
		return ;
	printf(CYAN"%ld Philo %d is sleeping\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_sleeping);
	return ;
}

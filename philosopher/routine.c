/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/16 22:24:38 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_solo_philo(t_infos *inf)
{
	long	norme;
	long	norme_id;

	printf(CYAN"0 PHILO %d is taking fork 1\n"RESET, inf[0].phi_id);
	usleep_remake(inf, inf->t_dying);
	norme = inf->t_dying;
	norme_id = inf[0].phi_id;
	printf(RED "%ld PHILO %ld IS DEAD\n" RESET, norme / 1000, norme_id);
	pthread_mutex_lock(&inf->check_stop);
	inf->stop_simulation = 1;
	pthread_mutex_unlock(&inf->check_stop);
}

void	*rout(void *infos)
{
	t_infos	*inf;
	
	inf = (t_infos *) infos;
	if (inf->phi_nb == 1)
	{
		handle_solo_philo(inf);
		return (NULL);
	}
	if (inf->phi_id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&inf->check_stop);
		if (inf->stop_simulation)
			break ;
		pthread_mutex_unlock(&inf->check_stop);
		if (!inf->stop_eat)
			eating(inf);
		pthread_mutex_lock(&inf->check_stop);
		if (inf->stop_eat == 1 || inf->stop_simulation)
			break ;
		pthread_mutex_unlock(&inf->check_stop);
		sleeping(inf);
		pthread_mutex_lock(&inf->check_stop);
		if (inf->stop_simulation)
			break ;
		pthread_mutex_unlock(&inf->check_stop);
		thinking(inf);
	}
	pthread_mutex_unlock(&inf->check_stop);
	return (NULL);
}

void	eating(t_infos *inf)
{
	long	time;

	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->fork[inf->left_fork]);
		pthread_mutex_unlock(&inf->fork[inf->right_fork]);
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	time = print_time(inf) - inf->start_time;
	printf("%ld Philo %d has taken forks\n", time, inf->phi_id);
	printf(GREEN"%ld Philo %d is eating\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_eating);
	pthread_mutex_lock(&inf->check_l_meal);
	inf->last_meal = print_time(inf);
	pthread_mutex_unlock(&inf->check_l_meal);
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	if (inf->eat_max && inf->eat_count == inf->eat_max)
	{
		pthread_mutex_lock(&inf->check_eat);
		inf->stop_eat = 1;
		pthread_mutex_unlock(&inf->check_eat);
	}
	return ;
}

void	thinking(t_infos *inf)
{
long	time;

	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	time = print_time(inf) - inf->start_time;
	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	printf(YELLOW"%ld Philo %d is thinking\n"RESET, time, inf->phi_id);
	return ;
}

void	sleeping(t_infos *inf)
{
	long	time;

	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	time = print_time(inf) - inf->start_time;
	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
	{
		pthread_mutex_unlock(&inf->check_stop);
		return ;
	}
	pthread_mutex_unlock(&inf->check_stop);
	printf(CYAN"%ld Philo %d is sleeping\n"RESET, time, inf->phi_id);
	usleep_remake(inf, inf->t_sleeping);
	return ;
}

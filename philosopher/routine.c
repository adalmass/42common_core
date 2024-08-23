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

void	*rout(void *infos)
{
	t_infos	*inf;

	inf = (t_infos *) infos;
	if (handle_solo_philo(inf))
		return (NULL);
	if (inf->phi_id % 2 == 0)
		usleep(150);
	while (1)
	{
		if (check_stop(inf))
			break ;
		eating(inf);
		if (check_stop(inf))
			break ;
		sleeping(inf);
		if (check_stop(inf))
			break ;
		thinking(inf);
		if (check_stop(inf))
			break ;
	}
	return (NULL);
}

void	eating(t_infos *inf)
{
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	if (check_stop_forks(inf, 1))
		return ;
	if (!print_infos(inf, 4))
		return ;
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	if (check_stop_forks(inf, 2))
		return ;
	if (!print_infos(inf, 5))
		return ;
	if (check_stop_forks(inf, 2))
		return ;
	if (!print_infos(inf, 1))
		return ;
	pthread_mutex_lock(&inf->check_l_meal);
	inf->last_meal = get_time(inf);
	pthread_mutex_unlock(&inf->check_l_meal);
	usleep_remake(inf, inf->t_eating);
	if (check_stop_forks(inf, 2))
		return ;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	eating2(inf);
	return ;
}

void	eating2(t_infos *inf)
{
	if (check_stop(inf))
		return ;
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_lock(&inf->check_eat);
	if (inf->eat_max && (inf->stop_eat == 0) && inf->eat_count == inf->eat_max)
	{
		inf->stop_eat = 1;
		pthread_mutex_unlock(&inf->check_eat);
		return ;
	}
	pthread_mutex_unlock(&inf->check_eat);
	return ;
}

void	thinking(t_infos *inf)
{
	if (!print_infos(inf, 2))
		return ;
	return ;
}

void	sleeping(t_infos *inf)
{
	if (!print_infos(inf, 3))
		return ;
	usleep_remake(inf, inf->t_sleeping);
	return ;
}

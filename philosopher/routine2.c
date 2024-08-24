/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:08:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/24 22:32:54 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_solo_philo(t_infos *inf)
{
	long	norme_dying;
	long	norme_id;

	if (inf->phi_nb == 1)
	{
		norme_id = inf[0].phi_id;
		norme_dying = inf->t_dying;
		printf(CYAN"0 PHILO %ld is taking fork 1\n"RST, norme_id);
		usleep_remake(inf, norme_dying);
		set_stop_simu(inf, (norme_dying / 1000) + 1);
		return (1);
	}
	return (0);
}

int	print_forks(t_infos *inf, int print)
{
	if (check_stop(inf))
		return (0);
	if (print == 4)
	{
		pthread_mutex_lock(&inf->ph->print);
		if (check_stop(inf))
		{
			pthread_mutex_unlock(&inf->ph->print);
			return (0);
		}
		printf("%ld Philo %d has taken fork 1\n", p_time(inf), inf->phi_id);
		pthread_mutex_unlock(&inf->ph->print);
	}
	if (print == 5)
	{
		pthread_mutex_lock(&inf->ph->print);
		if (check_stop(inf))
		{
			pthread_mutex_unlock(&inf->ph->print);
			return (0);
		}
		printf("%ld Philo %d has taken fork 2\n", p_time(inf), inf->phi_id);
		pthread_mutex_unlock(&inf->ph->print);
	}
	return (1);
}

int	print_infos(t_infos *inf, int print)
{
	if (!print_forks(inf, print))
		return (0);
	if (print == 1)
	{
		pthread_mutex_lock(&inf->ph->print);
		if (check_stop(inf))
		{
			pthread_mutex_unlock(&inf->ph->print);
			return (0);
		}
		printf(GREEN"%ld Philo %d is eating\n"RST, p_time(inf), inf->phi_id);
		pthread_mutex_unlock(&inf->ph->print);
	}
	if (print == 2)
	{
		pthread_mutex_lock(&inf->ph->print);
		if (check_stop(inf))
		{
			pthread_mutex_unlock(&inf->ph->print);
			return (0);
		}
		printf(YELLOW"%ld Philo %d is thinking\n"RST, p_time(inf), inf->phi_id);
		pthread_mutex_unlock(&inf->ph->print);
	}
	if (print == 3)
	{
		pthread_mutex_lock(&inf->ph->print);
		if (check_stop(inf))
		{
			pthread_mutex_unlock(&inf->ph->print);
			return (0);
		}
		printf(CYAN"%ld Philo %d is sleeping\n"RST, p_time(inf), inf->phi_id);
		pthread_mutex_unlock(&inf->ph->print);
	}
	return (1);
}

int	check_stop(t_infos *inf)
{
	pthread_mutex_lock(&inf->ph->check_stop);
	if (inf->ph->stop_simulation == 1)
	{
		pthread_mutex_unlock(&inf->ph->check_stop);
		return (1);
	}
	pthread_mutex_unlock(&inf->ph->check_stop);
	return (0);
}

int	check_stop_forks(t_infos *inf, int fork)
{
	pthread_mutex_lock(&inf->ph->check_stop);
	if (inf->ph->stop_simulation == 1)
	{
		pthread_mutex_unlock(&inf->ph->check_stop);
		if (fork == 1 || fork == 2)
			pthread_mutex_unlock(&inf->fork[inf->right_fork]);
		if (fork == 2)
			pthread_mutex_unlock(&inf->fork[inf->left_fork]);
		return (1);
	}
	pthread_mutex_unlock(&inf->ph->check_stop);
	return (0);
}

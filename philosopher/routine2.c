/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:08:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/23 16:25:43 by aldalmas         ###   ########.fr       */
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
		printf(CYAN"0 PHILO %ld is taking fork 1\n"RESET, norme_id);
		usleep_remake(inf, norme_dying);
		set_stop_simu(inf, (norme_dying / 1000) + 1);
		return (1);
	}
	return (0);
}

int	print_infos(t_infos *inf, int print)
{
	//long	time;

	if (check_stop(inf))
		return (0);
	//time = ptf_time(inf);
	if (!check_stop(inf) && print == 4)
		printf("%ld Philo %d has taken fork 1\n", ptf_time(inf), inf->phi_id);
	if (!check_stop(inf) && print == 5)
		printf("%ld Philo %d has taken fork 2\n", ptf_time(inf), inf->phi_id);
	if (!check_stop(inf) && print == 1)
		printf(GREEN"%ld Philo %d is eating\n"RESET, ptf_time(inf), inf->phi_id);
	if (!check_stop(inf) && print == 2)
		printf(YELLOW"%ld Philo %d is thinking\n"RESET, ptf_time(inf), inf->phi_id);
	if (!check_stop(inf) && print == 3)
		printf(CYAN"%ld Philo %d is sleeping\n"RESET, ptf_time(inf), inf->phi_id);
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
		if (fork == 1 || fork == 2)
			pthread_mutex_unlock(&inf->fork[inf->right_fork]);
		if (fork == 2)
			pthread_mutex_unlock(&inf->fork[inf->left_fork]);
		pthread_mutex_unlock(&inf->ph->check_stop);
		return (1);
	}
	pthread_mutex_unlock(&inf->ph->check_stop);
	return (0);
}

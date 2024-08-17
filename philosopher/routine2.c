/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:08:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/17 17:09:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_solo_philo(t_infos *inf)
{
	long	norme_dying;
	long	norme_id;

	norme_id = inf[0].phi_id;
	norme_dying = inf->t_dying;
	printf(CYAN"0 PHILO %ld is taking fork 1\n"RESET, norme_id);
	usleep_remake(inf, norme_dying);
	set_stop_simu(inf, norme_dying / 1000);
}

int	rout2(t_infos *inf)
{
	if (inf->stop_eat == 1 || inf->stop_simulation)
		return (0);
	pthread_mutex_unlock(&inf->check_stop);
	sleeping(inf);
	pthread_mutex_lock(&inf->check_stop);
	if (inf->stop_simulation)
		return (0);
	pthread_mutex_unlock(&inf->check_stop);
	thinking(inf);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/25 19:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_join(t_ph *phi)
{
	int	i;

	i = 0;
	while (phi->phi[i])
	{
		pthread_join(phi->phi[i], NULL);
		i++;
	}
}

void    *try_activity(void *infos)
{
	t_infos *inf = (t_infos *) infos;
	(void) inf;
	//eating(infos, idx_philo);
	//thinking(infos, idx_philo);
	//sleeping(infos, idx_philo);
	return (NULL);
}

void    eating(t_ph *phi, int idx_philo)
{
	(void) phi;
	(void) idx_philo;
	//pthread_mutex_lock(&mutex); //fourchette de gauche
	//pthread_mutex_lock(&mutex); //fourchette de droite
	//printf("phi %d is eating\n", idx_philo);
	//usleep(phi->t_eating);
	//pthread_mutex_unlock(&mutex); //fourchette de gauche
	//pthread_mutex_unlock(&mutex); //fourchette de droite
}

void	thinking(t_ph *phi, int idx_philo)
{
	(void) phi;
	(void) idx_philo;
	//printf("phi %d is thinking\n", idx_philo);
	//usleep(phi->t_thinking);
}

void	sleeping(t_ph *phi, int idx_philo)
{
	(void) phi;
	(void) idx_philo;
	//printf("phi %d is sleeping\n", idx_philo);
	//usleep(phi->t_sleeping);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/26 12:30:50 by aldalmas         ###   ########.fr       */
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
	printf(RED "routine\n" RESET);
	t_infos *inf = (t_infos *) infos;
	eating(inf);
	thinking(inf);
	sleeping(inf);
	return (NULL);
}

void    eating(t_infos *inf)
{
	printf("Philo %d is eating\n", inf->phi_id);
	//pthread_mutex_lock(&mutex); //fourchette de gauche
	//pthread_mutex_lock(&mutex); //fourchette de droite
	//printf("phi %d is eating\n", idx_philo);
	//usleep(phi->t_eating);
	//pthread_mutex_unlock(&mutex); //fourchette de gauche
	//pthread_mutex_unlock(&mutex); //fourchette de droite
}

void	thinking(t_infos *inf)
{
	printf("Philo %d is thinking\n", inf->phi_id);
	//printf("phi %d is thinking\n", idx_philo);
	//usleep(phi->t_thinking);
}

void	sleeping(t_infos *inf)
{
	printf("Philo %d is sleeping\n", inf->phi_id);
	//printf("phi %d is sleeping\n", idx_philo);
	//usleep(phi->t_sleeping);
}

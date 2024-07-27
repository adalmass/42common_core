/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/27 20:06:21 by aldalmas         ###   ########.fr       */
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
//void    *try_activity(void *infos)
void    *try_activity(void *phi)
{
	//t_ph *philo = (t_ph *) phi;
	t_infos *philo = (t_infos *) phi;
	// philo = phi;
	//printf("ICI Philo %d is eating\n", philo->infos->phi_id);
	eating(philo);
	printf("fini manger\n");
	thinking(philo);
	printf("fini penser\n");
	sleeping(philo);
	printf("fini dormir\n");
	return (NULL);
}

void    eating(t_infos *philo)
{
	printf("essaye de manger\n");
	//pthread_mutex_lock(&philo->forks[0]);
	printf("Philo %d is eating\n", philo->phi_id);
	// usleep(philo->infos[0]->t_eating);
	usleep(1000);
	//pthread_mutex_unlock(&philo->forks[0]);
	printf("c est bon hamdoullah\n");
}

// void    eating(t_ph *philo)
// {
// 	printf("essaye de manger\n");
// 	pthread_mutex_lock(&philo->forks[0]);
// 	printf("Philo %d is eating\n", philo->infos->phi_id);
// 	// usleep(philo->infos[0]->t_eating);
// 	usleep(1000);
// 	pthread_mutex_unlock(&philo->forks[0]);
// 	printf("c est bon hamdoullah");
// }

void	thinking(t_infos *philo)
{
	printf("Philo %d is thinking\n", philo->phi_id);
	//printf("phi %d is thinking\n", idx_philo);
	//usleep(phi->t_thinking);
}

void	sleeping(t_infos *philo)
{
	printf("Philo %d is sleeping\n", philo->phi_id);
	// usleep(phi->infos[0]->t_sleeping);
	usleep(1000);
	//printf("phi %d is sleeping\n", idx_philo);
	//usleep(phi->t_sleeping);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/28 20:39:43 by aldalmas         ###   ########.fr       */
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
	printf("\nSleep %d\n", inf->t_sleeping);
	printf("dying %d\n", inf->t_dying);
	printf("eating %d\n", inf->t_eating);
	printf("eat_counter %d\n", inf->eat_counter);
	printf("Philo id %d\n\n", inf->phi_id);
	//printf("Philo nb %d\n\n", inf->phi->phi_nb);
	eating(inf);
	printf("fini manger\n");
	thinking(inf);
	printf("fini penser\n");
	sleeping(inf);
	printf("fini dormir\n");
	return (NULL);
}

void    eating(t_infos *inf)
{
	printf("essaye de manger\n");
	//pthread_mutex_lock(&philo->forks[0]);
	printf(YELLOW"Philo %d is eating\n"RESET, inf->phi_id);
	// usleep(philo->infos[0]->t_eating);
	usleep(1000);
	//pthread_mutex_unlock(&philo->forks[0]);
	printf("c est bon hamdoullah\n");
}

void	thinking(t_infos *inf)
{
	printf(YELLOW"Philo %d is thinking\n"RESET, inf->phi_id);
	//printf("phi %d is thinking\n", idx_philo);
	//usleep(phi->t_thinking);
}

void	sleeping(t_infos *inf)
{
	printf(YELLOW"Philo %d is sleeping\n"RESET, inf->phi_id);
	// usleep(phi->infos[0]->t_sleeping);
	usleep(1000);
	//printf("phi %d is sleeping\n", idx_philo);
	//usleep(phi->t_sleeping);
}

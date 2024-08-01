/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/01 20:00:55 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void    *try_activity(void *infos)
// {
// 	t_infos *inf = (t_infos *) infos; 
// 	// printf("\nSleep %d\n", inf->t_sleeping);
// 	// printf("dying %d\n", inf->t_dying);
// 	// printf("eating %d\n", inf->t_eating);
// 	// printf("eat_counter %d\n", inf->eat_counter);
// 	// printf("Philo id %d\n\n", inf->phi_id);
// 	//printf("Philo nb %d\n\n", inf->phi->phi_nb);
// 	while (inf->eat_counter)
// 	{
// 		eating(inf);
// 		// printf("fini manger\n");
// 		thinking(inf);
// 		// printf("fini penser\n");
// 		sleeping(inf);
// 		// printf("fini dormir\n");
		
// 	}
// 	return (NULL);
// }

void    *try_activity(void *infos)
{
	t_infos *inf = (t_infos *) infos;
	eating(inf);
	// printf("fini manger\n");
	thinking(inf);
	// printf("fini penser\n");
	sleeping(inf);
	// printf("fini dormir\n");
	return (NULL);
}

void    eating(t_infos *inf)
{
	if (inf->phi_id % 2 != 0)
		usleep(100);
	// printf("Try to eat\n");
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);

	printf(GREEN"Philo %d is eating\n"RESET, inf->phi_id);
	usleep(100000);
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
}

void	thinking(t_infos *inf)
{
	printf(YELLOW"Philo %d is thinking\n"RESET, inf->phi_id);
	//printf("phi %d is thinking\n", idx_philo);
	//usleep(phi->t_thinking);
	usleep(100000);
}

void	sleeping(t_infos *inf)
{
	printf(CYAN"Philo %d is sleeping\n"RESET, inf->phi_id);
	// usleep(phi->infos[0]->t_sleeping);
	usleep(100000);
}

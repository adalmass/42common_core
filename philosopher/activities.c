/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/01 21:23:52 by aldalmas         ###   ########.fr       */
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
	if (inf->eat_count != inf->eat_max)
		eating(inf);
	if (inf->stop_eat == 1)
		return (NULL);
	thinking(inf);
	sleeping(inf);
	return (NULL);
}

void    eating(t_infos *inf)
{
	if (inf->phi_id % 2 != 0)
		usleep(100);
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	printf(GREEN"Philo %d is eating\n"RESET, inf->phi_id);
	inf->eat_count++;
	usleep(inf->t_eating);
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->eat_count == inf->eat_max)
	{
		inf->stop_eat = 1;
		printf(RED"ARRETE DE BOUFFER GROS PORC\n" RESET);
	}
}

void	thinking(t_infos *inf)
{
	printf(YELLOW"Philo %d is thinking\n"RESET, inf->phi_id);
}

void	sleeping(t_infos *inf)
{
	printf(CYAN"Philo %d is sleeping\n"RESET, inf->phi_id);
	usleep(inf->t_sleeping);
}

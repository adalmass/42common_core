/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/08 21:59:07 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fonction_qui_gere_la_mort(void *infos)
{
	long	current_time;

	t_infos *inf = (t_infos *) infos;
	while (1)
	{
		if (inf->last_time_eat <= 0)
			return (NULL);
		current_time = get_time(inf);
		//printf("Philo %d current time : %ld\nlast time eat: %ld\n", inf->phi_id, current_time, inf->last_time_eat);
		current_time = current_time - inf->last_time_eat;
		//printf("Philo %d resultat :               %ld %d\n", inf->phi_id, current_time, inf->t_dying);
		if (current_time > inf->t_dying)
		{
			printf(RED "PHILO %d IS DEAD LOL\n" RESET, inf->phi_id);
			exit (1);
		}
	}
	return (NULL);
}

void    *try_activity(void *infos)
{
	t_infos *inf = (t_infos *) infos;

	if (!inf->stop_eat)
		eating(inf);
	if (inf->stop_eat == 1)
		return (NULL);
	sleeping(inf);
	thinking(inf);
	return (NULL);
}

void	eating(t_infos *inf)
{
	if (inf->phi_nb % 2 == 0 && inf->phi_id % 2 == 0)
		usleep(150);
	pthread_mutex_lock(&inf->fork[inf->left_fork]);
	pthread_mutex_lock(&inf->fork[inf->right_fork]);
	printf(GREEN"Philo %d is eating\n"RESET, inf->phi_id);
	usleep(inf->t_eating);
	inf->last_time_eat = get_time(inf);
	if (inf->eat_max)
		inf->eat_count++;
	pthread_mutex_unlock(&inf->fork[inf->left_fork]);
	pthread_mutex_unlock(&inf->fork[inf->right_fork]);
	if (inf->eat_max && inf->eat_count == inf->eat_max)
		inf->stop_eat = 1;
	return;
}

void	thinking(t_infos *inf)
{
	printf(YELLOW"Philo %d is thinking\n"RESET, inf->phi_id);
	return ;
}

void	sleeping(t_infos *inf)
{
	printf(CYAN"Philo %d is sleeping\n"RESET, inf->phi_id);
	usleep(inf->t_sleeping);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:30:00 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 18:37:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    try_activity(t_philo *philo)
{
    return ;
}

void    eating(t_philo *philo)
{ 
    
    //pthread_mutex_lock(&mutex); //fourchette de gauche
    //pthread_mutex_lock(&mutex); //fourchette de droite
    printf("Philo %d is eating\n", philo->philo);
    usleep(philo->t_eating);
    //pthread_mutex_unlock(&mutex); //fourchette de gauche
    //pthread_mutex_unlock(&mutex); //fourchette de droite
}

void    thinking(t_philo *philo)
{ 
    printf("Philo %d is thinking\n", philo->philo);
    usleep(philo->t_thinking);
}

void    sleeping(t_philo *philo)
{
    printf("Philo %d is sleeping\n", philo->philo);
    usleep(philo->t_sleeping);

    return ;    
}

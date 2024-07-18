/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:44 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 19:24:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_struct(t_philo *philo, char **av)
{
    philo->t_thinking = 0;
    philo->philo_nb = ft_atoi(av[1]);
    philo->t_dying = ft_atoi(av[2]);
    philo->t_eating = ft_atoi(av[3]);
    philo->t_sleeping = ft_atoi(av[4]);
    if (av[5])
        philo->eat_counter = ft_atoi(av[5]);
    else
        philo->eat_counter = 0;
}


void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
    //pthread_t   philo[number];
    while (i < philo->philo_nb)
    {
        pthread_create(&philo[i], NULL, &try_activity, (t_philo *)philo);
        i++;
    }
}

void    create_fork(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->philo_nb)
    {
        pthread_mutex_init(&philo->mutex[i], NULL);
        i++;
    }
}

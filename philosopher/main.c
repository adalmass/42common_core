/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 18:51:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    parsing(int ac, char **av)
{
    int x;
    int y;

    y = 1;
    x = 0;
    (void) av;
    if (ac > 6)
        error_found("too many arguments (max 5)");
    if (ac < 5)
        error_found("too few arguments (min 4)");
    if (ft_atoi(av[1]) <= 0)
        error_found("we need at leat one philosopher");
    while (av[y])
    {
        x = 0;
        while (av[y][x])
        {
            printf("%c", av[y][x]);
            if (!ft_isdigit(av[y][x]))
                error_found("args must be digits");
            x++;
        }
        printf("\n");
        y++;
    }
}

void    create_philo(int number)
{
    int i;

    i = 0;
    //pthread_t   philo[number];
    while (i < number)
    {
        //pthread_create(&philo[i], NULL, try_activity, &philo[i]);
        i++;
    }
}

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

int main(int ac, char **av)
{
    t_philo     philo;
    struct timeval time;

    (void) ac;
    (void) av;
    parsing(ac, av);
    init_struct(&philo, av);
    print_time(&time);
    usleep(1000000);
    print_time(&time);
}

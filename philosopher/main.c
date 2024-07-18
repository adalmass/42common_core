/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 19:22:11 by aldalmas         ###   ########.fr       */
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
            if (!ft_isdigit(av[y][x]))
                error_found("args must be digits");
            x++;
        }
        y++;
    }
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

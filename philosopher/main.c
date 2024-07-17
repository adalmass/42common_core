/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/17 15:53:56 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_time(struct timeval *time)
{
    gettimeofday(time, NULL);
    printf("%ld\n", time->tv_sec);
}

int main(int ac, char **av)
{
    struct timeval time;

    (void) ac;
    (void) av;
    print_time(&time);
    usleep(1);
    print_time(&time);
}

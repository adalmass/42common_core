/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/03 16:01:44 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    error_found(char *msg)
{
    printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}
int count_eating_time(t_infos *inf)
{
    gettimeofday(&inf->time, NULL);
    printf("CACA: %ld\n", inf->time.tv_usec * 1000);
    return (1);
}

void    print_time(struct timeval *time)
{
    gettimeofday(time, NULL);
    printf("millisec: ");
    printf("%ld,%ld\n", time->tv_sec, time->tv_usec / 1000);
}

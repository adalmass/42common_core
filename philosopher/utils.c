/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 17:15:19 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    error_found(char *msg)
{
    printf(RED "ERROR: %s\n" RESET, msg);
    exit (1);
}

void    print_time(struct timeval *time)
{
    gettimeofday(time, NULL);
    printf("microsec: ");
    printf("%ld\n", time->tv_sec);
}

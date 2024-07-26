/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/26 11:02:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    error_found(char *msg)
{
    printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}

void    print_time(struct timeval *time)
{
    gettimeofday(time, NULL);
    printf("microsec: ");
    printf("%ld\n", time->tv_sec);
}

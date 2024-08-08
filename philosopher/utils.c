/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/08/08 21:22:05 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_found(char *msg)
{
	printf(YELLOW "PHILO ERROR: %s\n" RESET, msg);
}

long	get_time(t_infos *inf)
{
	long	current_time;

	gettimeofday(&inf->time, NULL);
	current_time = (inf->time.tv_sec * 1000000) + inf->time.tv_usec;
	return (current_time);
}

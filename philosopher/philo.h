/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:13:55 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/17 14:13:55 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_nb;
	int				t_eating;
	int				t_thinking;
	int				t_sleeping;
	int				t_dying;
	int				eat_counter;
	pthread_t		*philo;
	pthread_mutex_t	*mutex;

}					t_philo;

// --- parsing.c
void	parsing(int ac, char **av);

// --- utils.c
void	error_found(char *msg);
void	print_time(struct timeval *time);

// --- microlibft.c
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

// --- activities.c
void	try_activity(t_philo *philo);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
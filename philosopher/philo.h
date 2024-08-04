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

typedef struct s_ph t_ph;
typedef struct s_infos t_infos;

typedef struct s_infos
{
	int				phi_nb;
	int				phi_id;
	int				t_eating;
	int				t_sleeping;
	int				t_dying;
	int				left_fork;
	int				right_fork;
	int				eat_max;
	int				eat_count;
	int				stop_eat;
	long			last_time_eat;
	struct timeval	time;
	struct timeval	timer_eat;
	pthread_mutex_t	*fork;
}					t_infos;

typedef struct s_ph
{
	int				t_eating;
	int				t_sleeping;
	int				t_dying;
	int				eat_max;
	int				phi_nb;
	t_infos			*infos;
}					t_ph;

// --- parsing.c
int		parsing(int ac, char **av);
int		check_arg(char *arg);
int 	count_eating_time(t_infos *inf);

// --- init.c
int		init_phi(t_ph *phi, char **av);
void	init_infos(t_ph *phi, int idx_philo);
void	start_simulation(t_ph *phi);
void	create_mutex(t_ph *phi, pthread_mutex_t *forks);
//void	destroy_mutex(t_ph *phi);

// --- utils.c
void	error_found(char *msg);
void	print_time(struct timeval *time);

// --- microlibft.c
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		handle_int_limit(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// --- activities.c
void    *try_activity(void *infos);
void    eating(t_infos *inf);
void    sleeping(t_infos *inf);
void    thinking(t_infos *inf);
void	fonction_qui_gere_la_mort(void *phi);

#endif
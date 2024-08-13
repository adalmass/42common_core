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
	int				stop_simulation;
	int				is_dead;
	long			last_time_eat;
	long			start_time;
	struct timeval	time;
	pthread_mutex_t	*print;
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
long	print_time(t_infos *inf);
void	usleep_remake(t_infos *inf, long sleep);

// --- init.c
int		init_phi(t_ph *phi, char **av);
void	init_infos(t_ph *phi, pthread_mutex_t *forks, long time);

void	start_simulation(t_ph *phi);
void	create_mutex(t_ph *phi, pthread_mutex_t *forks);

// --- utils.c
void	error_found(char *msg);
void	init_mutex(t_ph *phi, pthread_mutex_t *forks);
void	join_threads(t_ph *phi, pthread_t *philo);
void	destroy_mutex(t_ph *phi);

// --- microlibft.c
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		handle_int_limit(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// --- activities.c
void	*fonction_qui_gere_la_mort(void *phi);
void    *routine(void *infos);
void    eating(t_infos *inf);
void    sleeping(t_infos *inf);
void    thinking(t_infos *inf);

#endif
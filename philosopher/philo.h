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

#ifndef phi_H
# define phi_H

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

typedef struct s_infos
{
	int				phi_id;
	int				t_eating;
	int				t_sleeping;
	int				t_dying;
	int				eat_counter;
}					t_infos;

typedef struct s_phi
{
	int				phi_nb;
	t_infos			**infos;
	pthread_t		*phi;
	pthread_mutex_t	*forks;

}					t_ph;

// --- parsing.c
int		parsing(int ac, char **av);
int		check_arg(char *arg);

// --- init.c
int		init_struct(t_ph *phi, t_infos *inf, char **av);
void	create_phi(t_ph *phi, t_infos *inf);
void	create_fork(t_ph *phi);
void	philo_join(t_ph *phi);

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
void    eating(t_ph *phi, int idx_philo);
void	thinking(t_ph *phi, int idx_philo);
void	sleeping(t_ph *phi, int idx_philo);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:42:12 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/25 11:47:49 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>

typedef struct s_pipex{
	int			infile_fd;
	int			outfile_fd;
	int			len_envp;
	int			path_found;
	int			path_idx;
	char		**envp;
	char		**copy_envp;
	char		**path;
	char		*cmd1;
	char		*cmd2;
}				t_pipex;

// --- main.c
char	*check_command(t_pipex *pp, char *command);

// --- utils.c

// --- init.c
void	init_tabs(t_pipex *pp, char **envp);
void	init_int(t_pipex *pp);
void	check_files(t_pipex *pp, char **av);

// --- manage_errors.c
void	ft_error(char *error_msg);

// --- mini_libft/
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *stock, char *temp);

int		ft_printf(const char *s, ...);
int		ft_putchar_ptf(char c);
int		ft_putstr_ptf(char *s);
int		ft_strchr_ptf(char *s, char c);
void	ft_putnbr_ptf(long long n, char *base, int b_len);
void	ft_u_putnbr_ptf(unsigned long long n, char *base, int b_len);
int		get_nb_len(long long n, int b_len);
int		get_u_nb_len(unsigned long long n, int b_len);
void	search_format(char c, long long arg, int *i, int *len);

#endif
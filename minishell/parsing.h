/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:42:12 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 15:07:05 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_parse {
        int     count;
        int     len_cmd_line;
        int     pipe_count;
        int     pip_first_error;
        int     redir_l_count;
        int     redir_r_count;
        int     redir_first_error;
        char    *cmd_line;
        char    *cmd_line_spaces;
        char    **cmd_table;
}               t_parse;


// --- main.c (qui sera parse.c plus tard)
void    parsing(t_parse *p);
void    create_cmds_table(t_parse *p);

// --- check_cmd_line.c
void    check_redir_n_pipes(t_parse *p);
void    check_cmd_line(t_parse *p);

// --- handle_spaces.c
void    handle_spaces(t_parse *p, int cmd_idx);

// --- redir_n_pipe.c
void    redir_left(t_parse *p, char c);
void    redir_right(t_parse *p, char next_char);
void    check_pipe(t_parse *p, char next_char);
void    check_first_char(t_parse *p);

// --- tools.c
void	parse_error(char *error_msg);
void	init_struct(t_parse *p);
void    prompt(void);


// --- mini_libft/
int	ft_strlen(const char *s);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_free(char *stock, char *temp);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

int	ft_printf(const char *s, ...);
int	ft_putchar_ptf(char c);
int	ft_putstr_ptf(char *s);
int	ft_strchr_ptf(char *s, char c);
void	ft_putnbr_ptf(long long n, char *base, int b_len);
void	ft_u_putnbr_ptf(unsigned long long n, char *base, int b_len);
int	get_nb_len(long long n, int b_len);
int	get_u_nb_len(unsigned long long n, int b_len);
void	search_format(char c, long long arg, int *i, int *len);

#endif
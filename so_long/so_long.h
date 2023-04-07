/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:29:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/07 17:11:38 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct	s_minilbx {
	void		*img;
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct	s_map {
	int			x;
	int 		y;
	int			fd;
	char		*temp;
	char		*map_str;
	char		**map;
}			    t_map;

typedef struct	s_parsing {
	int			wall;
	int			path;
	int			coin;
	int			exit;
	int			spawn;
	int			backslash_n;
	int			other_char;
}				t_parse;

//--- startup_checks.c
int		check_args_nb(int ac);
int		check_fd_format(char *av);
int		check_fd_opening(int fd);
void	startup_checks(int ac, char *av);

// --- initialize.c
void	initialize_pase(t_parse *parse);
void	initialize_map(t_map *map);

// --- parsing.c
int		is_a_valid_map(char *temp, t_parse *parse);
void	get_map_str(t_map *map);
void	get_map(t_map *map, t_parse *parse);

// --- utils.c
int		search_char(char *haystack, char needle);

// --- errors.c
int		check_if_errors2(t_parse *parse);
int		check_if_errors(t_parse *parse);
int		check_len_size(int good_len, int actual_len, char *temp);

#endif
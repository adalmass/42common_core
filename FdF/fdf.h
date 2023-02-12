/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:05 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/11 17:03:00 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# ifndef BUFFER
#  define BUFFER 2000
# endif

/*
typedef struct s_minilbx {
	void		*img;
	void		*mlx;
	void		*window;
}				t_minilbx;
*/

typedef struct s_map {
	int			x;
	int			y;
	int			z;
	int			fd;
	int			map_char_len;
	int			**map_int;
	char		**map_char;
	char		***map; // pour pouvoir recuperer les valeurs contenues au map[2][2][0] (qui est 1) car ce sont des chaines de caracteres
}				t_map;

// error_checker.c
int		check_args_nb(int ac);
int		check_fd_format(char *av);
int		check_fd_opening(int fd);

// get_line.c
void	get_map_char(t_map *map);
void	get_map_int(t_map *map);
void	get_map(t_map *map);

// fdf_utils.c
void	check_point(int x, int x_end, int y, int y_end);

#endif
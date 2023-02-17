/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:05 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/16 16:34:41 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# ifndef BUFFER
#  define BUFFER 10
# endif

typedef struct s_img{
	int			endian;
	int			bpp;
	int			l_length;
	char		*addr;
	void		*img;
}				t_img;

typedef struct s_minilbx {
	int			x;
	int			y;
	int			z;
	void		*mlx;	
	void		*window;
}				t_minilbx;

typedef struct s_map {
	int			x_fd_len;
	int			y_fd_len;
	int			fd;
	int			map_char_len;
	int			**map_int;
	char		**map_char;
	char		***map; // pour pouvoir recuperer les valeurs contenues au map[2][2][0] (qui est 1 dans 42.fdf) car ce sont des chaines de caracteres 
}				t_map;

// error_checker.c
int		check_args_nb(int ac);
int		check_fd_format(char *av);
int		check_fd_opening(int fd);
int		check_mlx_init(t_minilbx *mlx);
int		check_mlx_window(t_minilbx *mlx);

// get_fd_data.c
void	get_map_char(t_map *map);
void	get_map_int(t_map *map);
void	get_map(t_map *map);

// fdf_utils.c
void	check_point(int x, int x_end, int y, int y_end);

// key_events.c
int		check_event(int key);
int		shutdown(void);

// free_and_clear.c
void	clear_map_int(t_map *map);
void	clear_map(t_map *map);
void	free_tab(char **tab);

// draw.c
void	create_img(t_minilbx *mlx, t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	fdf(t_minilbx *mlx, t_map *map, t_img *img);

#endif
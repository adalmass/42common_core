/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:05 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/17 11:11:29 by aldalmas         ###   ########.fr       */
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
	int			lght;
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

// security.c
void	struct_initializer(t_minilbx *mlx, t_map *map, t_img *img);
void	mlx_initializer(t_minilbx *mlx, t_img *img);

// get_fd_data.c
void	get_map_char(t_map *map);
void	get_map_int(t_map *map);
void	get_map(t_map *map);
void	fill_all_tabs(t_map *map, char *av);

// fdf_utils.c
void	check_point(int x, int x_end, int y, int y_end);

// key_events.c
int		check_event(int key);
int		shutdown(void);

// draw.c
void	create_img(t_minilbx *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
void	fdf(t_minilbx *mlx, t_map *map, t_img *img);

#endif
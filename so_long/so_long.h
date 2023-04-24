/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:29:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/24 18:15:50 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_item_xy {
	int			exit_x;
	int			exit_y;
	int			spawn_x;
	int			spawn_y;
}				t_item_xy;

typedef struct s_minilbx {
	void		*img;
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct s_map {
	int			x;
	int			y;
	int			fd;
	int			good_len;
	int			lines;
	char		*temp;
	char		*map_str;
	char		**map;
	char		**map_path;
}				t_map;

typedef struct s_parsing {
	int			wall;
	int			path;
	int			coin;
	int			coin_found;
	int			exit;
	int			exit_found;
	int			spawn;
	int			backslash_n;
	int			other_char;
	int			modified;
}				t_parse;

//--- startup_checks.c
int		check_fd_opening(int fd);
void	check_args_nb(int ac);
void	check_fd_format(char *av);
void	startup_checks(int ac, char *av);

// --- initialize.c
void	initialize_parse(t_parse *parse);
void	initialize_map(t_map *map);
void	initialize_item_xy(t_item_xy *item_xy);
void	structs_initializer(t_parse *parse, t_map *map, t_item_xy *item_xy);

// --- manage_maps.c
void	get_map_str(t_map *map);
void	get_map(t_map *map, t_parse *parse);
void	copy_map(t_map *map, t_item_xy *item_xy);

// --- parsing.c
int		is_wall(t_map *map);
int		is_a_valid_map(char *temp, t_parse *parse);
void	check_walls(t_map *map);

// --- utils.c
int		search_char(char *haystack, char needle);

// --- errors.c
int		check_if_errors(t_parse *parse);
int		check_if_errors2(t_parse *parse);
int		check_len_size(t_map *map, int actual_len);
void	ft_exit(char *error_msg);

// --- check_path.c
void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy);
void	DEBUG_print_map(t_map *map, t_parse *parse);

// --- pathfinding.c
int		last_verif(t_map *map, t_parse *parse, t_item_xy *item_xy);
void	pathfinding(t_map *map, t_parse *parse, t_item_xy *item_xy);
void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy);
void	verifications_y(t_map *map, t_parse *parse);
void	verifications_x(t_map *map, t_parse *parse);

// --- pathfinding2.c
int		search_exit(t_map *map, t_parse *parse, t_item_xy *item);
void	search_coin(t_map *map, t_parse *parse);

#endif
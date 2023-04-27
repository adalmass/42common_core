/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:06:50 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 15:24:07 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_str(t_map *map)
{
	int	first_turn;
	int	good_len;

	map->map_str = ft_strdup("");
	first_turn = 1;
	while (1)
	{
		map->temp = get_next_line(map->fd);
		if (!map->temp)
			break ;
		if (first_turn)
		{
			map->good_len = s_len(map->temp);
			first_turn = 0;
		}
		if (check_len_size(map, s_len(map->temp)))
			map->map_str = ft_strjoin_gnl(map->map_str, map->temp);
		else
		{
			ft_putstr("ERROR : lines does not have the same size\n");
			exit (1);
		}
		map->lines++;
		free(map->temp);
	}
}

void	get_map(t_map *map, t_parse *parse)
{
	get_map_str(map);
	is_a_valid_map(map->map_str, parse);
	map->map = ft_split(map->map_str, '\n');
}

void	get_exit_xy(t_map *map, t_item_xy *item_xy)
{
	if (map->map_path[map->y][map->x] == 'E')
	{
		item_xy->exit_x = map->x;
		item_xy->exit_y = map->y;
	}
	else if (map->map_path[map->y][map->x] == 'P')
	{
		item_xy->spawn_x = map->x;
		item_xy->spawn_y = map->y;
	}
}

void	copy_map(t_map *map, t_item_xy *item_xy)
{
	map->map_path = malloc(sizeof(char *) * map->lines + 1);
	if (!map->map_path)
		ft_exit("ERROR : malloc failed for **map_path (check_path.c)");
	while (map->map[map->y])
	{
		map->map_path[map->y] = malloc(sizeof(char) * map->good_len + 1);
		if (!map->map_path[map->y])
			ft_exit("ERROR : malloc failed for map_path[y] (check_path.c)");
		while (map->map[map->y][map->x])
		{
			map->map_path[map->y][map->x] = map->map[map->y][map->x];
			get_exit_xy(map, item_xy);
			map->x++;
		}
		map->map_path[map->y][map->x] = '\0';
		map->x = 0;
		map->y++;
	}
	map->map_path[map->y] = NULL;
	is_valids_walls(map);
}

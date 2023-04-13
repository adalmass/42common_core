/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:35:27 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 16:04:07 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_item_xy(t_map *map, t_item_xy *item_xy)
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
		exit (1);
	while (map->map[map->y])
	{
		map->map_path[map->y] = malloc(sizeof(char) * map->good_len + 1);
		if (!map->map_path[map->y])
			exit (1);
		while (map->map[map->y][map->x])
		{
			map->map_path[map->y][map->x] = map->map[map->y][map->x];
			get_item_xy(map, item_xy);
			map->x++;
		}
		map->map_path[map->y][map->x] = '\0';
		map->x = 0;
		map->y++;
	}
	map->map_path[map->y] = NULL;
	map->y = 0;
	map->x = 0;
}

void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	map->y = item_xy->spawn_y;
	map->x = item_xy->spawn_x;
	int i = 0; // a suppr
	while (i < 30)
	{
		move_pathfinding(map, parse);
		i++;
	}
	
	// debbug, a supp
	map->x = 0;
	map->y = 0;
	while (map->map_path[map->y])
	{
		ft_putstr(map->map_path[map->y]);
		ft_putchar('\n');
		map->y++;
	}
	ft_printf("Coin(s) recolté(s) : %d/%d\n", parse->coin_get, parse->coin);
}

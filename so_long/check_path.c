/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:35:27 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/14 17:44:22 by aldalmas         ###   ########.fr       */
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
		ft_exit("ERROR : malloc failed for **map_path (check_path.c)");
	while (map->map[map->y])
	{
		map->map_path[map->y] = malloc(sizeof(char) * map->good_len + 1);
		if (!map->map_path[map->y])
			ft_exit("ERROR : malloc failed for map_path[y] (check_path.c)");
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
}

void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	map->y = 1;
	map->x = 1;
	ft_printf("y : %d | x : %d\n", map->y, map->x);
	int i = 0; // a suppr
	while (map->blocked < 2)
	{
		ft_printf("tour n_%d\n", i + 1);
		map->map_path[map->y][map->x] = 'o';
		pathfinding(map, parse, item_xy);
		print_map(map, parse); // a supp
		i++;
	}
}

void	print_map(t_map *map, t_parse *parse)  // a supp
{
	int	y = 0;
	while (map->map_path[y])
	{
		ft_putstr(map->map_path[y]);
		ft_putchar('\n');
		y++;
	}
	ft_printf("Coin(s) recolté(s) : %d/%d\n", parse->coin_get, parse->coin);
}

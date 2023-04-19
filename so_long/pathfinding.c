/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/19 16:35:47 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	update_visited_path(t_map *map)
{
	char	c;

	c = 'k';
	map->map_path[map->y][map->x] = c;
	if (map->map_path[map->y + 1][map->x] != '1')
		map->map_path[map->y + 1][map->x] = c;
	if (map->map_path[map->y - 1][map->x] != '1')
		map->map_path[map->y - 1][map->x] = c;
	if (map->map_path[map->y][map->x + 1] != '1')
		map->map_path[map->y][map->x + 1] = c;
	if (map->map_path[map->y][map->x - 1] != '1')
		map->map_path[map->y][map->x - 1] = c;
}
*/
void	search_coin(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'C')
	{
		map->map_path[map->y][map->x] = 'x';
		parse->coin_found++;
	}
}

void	search_spawn(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'P')
	{
		map->map_path[map->y][map->x] = 's';
		parse->spawn_found++;
	}
}

void	search_exit(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'E')
	{
		map->map_path[map->y][map->x] = '1';
		parse->exit_found++;
	}
}

void	travel_map(t_map *map, t_parse *parse)
{
	map->y = 1;
	map->x = 0;
	while (map->y < map->lines - 1)
	{
		while (map->map_path[map->y][map->x])
		{
			if (map->map_path[map->y][map->x] != '1')
				map->x++;
			search_coin(map, parse);
			search_spawn(map, parse);
			search_exit(map, parse);
			map->map_path[map->y][map->x] = 'o';
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
}

void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	travel_map(map, parse);
	print_map(map, parse);
	if (parse->coin_found == parse->coin
		&& parse->exit_found && parse->spawn_found)
		ft_putstr("pathfinding check\n");
	else
		ft_exit("ERROR : the player won't be able to reach coin(s) or exit\n");
}

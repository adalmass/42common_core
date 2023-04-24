/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:47:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/24 18:00:14 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_coin(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'C')
	{
		map->map_path[map->y][map->x] = 'x';
		parse->coin_found++;
	}
	else if (map->map_path[map->y][map->x + 1] == 'C')
	{
		map->map_path[map->y][map->x + 1] = 'x';
		parse->coin_found++;
	}
	else if (map->map_path[map->y][map->x - 1] == 'C')
	{
		map->map_path[map->y][map->x - 1] = 'x';
		parse->coin_found++;
	}
	else if (map->map_path[map->y + 1][map->x] == 'C')
	{
		map->map_path[map->y + 1][map->x] = 'x';
		parse->coin_found++;
	}
	else if (map->map_path[map->y - 1][map->x] == 'C')
	{
		map->map_path[map->y - 1][map->x] = 'x';
		parse->coin_found++;
	}
}

int	search_exit(t_map *map, t_parse *parse, t_item_xy *item)
{
	if (map->map_path[item->exit_y - 1][item->exit_x] == 'x'
		|| map->map_path[item->exit_y][item->exit_x - 1] == 'x'
		|| map->map_path[item->exit_y + 1][item->exit_x] == 'x'
		|| map->map_path[item->exit_y][item->exit_x + 1] == 'x')
	{
		parse->exit_found++;
		return (1);
	}
	return (0);
}

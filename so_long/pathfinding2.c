/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:47:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/22 10:34:30 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_coin(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'C'
		|| map->map_path[map->y][map->x + 1] == 'C'
		|| map->map_path[map->y][map->x - 1] == 'C'
		|| map->map_path[map->y + 1][map->x] == 'C'
		|| map->map_path[map->y - 1][map->x] == 'C')
		{
			parse->coin_found++;
		}
}

void	search_spawn(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y][map->x] == 'P'
		|| map->map_path[map->y][map->x + 1] == 'P'
		|| map->map_path[map->y][map->x - 1] == 'P'
		|| map->map_path[map->y + 1][map->x] == 'P'
		|| map->map_path[map->y - 1][map->x] == 'P')
	{
		if (!parse->spawn_found)
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
	else if (map->map_path[map->y][map->x + 1] == 'E')
	{
		map->map_path[map->y][map->x + 1] = '1';
		parse->exit_found++;
	}
	else if (map->map_path[map->y][map->x - 1] == 'E')
	{
		map->map_path[map->y][map->x - 1] = '1';
		parse->exit_found++;
	}
	else if (map->map_path[map->y + 1][map->x] == 'E')
	{
		map->map_path[map->y + 1][map->x] = '1';
		parse->exit_found++;
	}
	else if (map->map_path[map->y - 1][map->x] == 'E')
	{
		map->map_path[map->y - 1][map->x] = '1';
		parse->exit_found++;
	}
}

void	if_exit_multicounted(t_parse *parse)
{
	if (parse->exit_found > 1)
		parse->exit_found = 1;
}

void	search_items(t_map *map, t_parse *parse)
{
	search_coin(map, parse);
	search_spawn(map, parse);
	search_exit(map, parse);
	if_exit_multicounted(parse);
}
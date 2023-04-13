/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 14:44:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	detect_coin(t_map *map)
{
	if (map->map_path[map->y + 1][map->x] == 'C')
	{
		map->map_path[map->y + 1][map->x] = 'o';
		map->y++;
		return (1);
	}
	else if (map->map_path[map->y - 1][map->x] == 'C')
	{
		map->map_path[map->y - 1][map->x] = 'o';
		map->y--;
		return (1);
	}
	else if (map->map_path[map->y][map->x - 1] == 'C')
	{
		map->map_path[map->y][map->x - 1] = 'o';
		map->x--;
		return (1);
	}
	else if (map->map_path[map->y][map->x - 1] == 'C')
	{
		map->map_path[map->y][map->x + 1] = 'o';
		map->x++;
		return (1);
	}
	return (0);
}

int	detect_exit(t_map *map, t_parse *parse)
{
	if (map->map_path[map->y + 1][map->x] == 'E')
	{
		map->map_path[map->y + 1][map->x] = '1';
		parse->exit_found++;
		return (1);
	}
	else if (map->map_path[map->y - 1][map->x] == 'E')
	{
		map->map_path[map->y - 1][map->x] = '1';
		parse->exit_found++;
		return (1);
	}
	else if (map->map_path[map->y][map->x - 1] == 'E')
	{
		map->map_path[map->y][map->x - 1] = '1';
		parse->exit_found++;
		return (1);
	}
	else if (map->map_path[map->y][map->x - 1] == 'E')
	{
		map->map_path[map->y][map->x + 1] = '1';
		parse->exit_found++;
		return (1);
	}
	return (0);
}

int	move(t_map *map)
{
	if (map->map_path[map->y][map->x + 1] != '1'
		&& map->map_path[map->y][map->x + 1] != 'o')
		map->x++;
	return (0);
}

int	detect_items(t_map *map, t_parse *parse)
{
	if (detect_coin(map))
		parse->coin_get++;
	if ((parse->coin_get == parse->coin) && parse->exit_found)
	{
		ft_putstr("path finding check\n");
		return (1);
	}
	return (0);
}

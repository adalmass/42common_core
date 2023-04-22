/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/22 15:24:19 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int pathfinding(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	int	modified;
	int x = 0;
	int y = 0;

	map->y = item_xy->spawn_y;
	map->x = item_xy->spawn_x;
	map->map_path[map->y][map->x] = 'x';
	modified = 1;
	while (modified)
	{
		modified = 0;
		y = 0;
		while (y < map->lines - 1)
		{
			x = 0;
			while (map->map_path[y][x])
			{
				if (y - 1 >= 0 && (map->map_path[y - 1][x] == '0' || map->map_path[y - 1][x] == 'C'))
				{
					if (map->map_path[y - 1][x] == 'C')
						parse->coin_found++;
					map->map_path[y - 1][x] = 'x';
					modified++;
				}
				if (x - 1 >= 0 &&(map->map_path[y][x - 1] == '0' || map->map_path[y][x - 1] == 'C'))
				{
					if (map->map_path[y][x - 1] == 'C')
						parse->coin_found++;
					map->map_path[y][x - 1] = 'x';
					modified++;
				}
				if (y + 1 >= 0 && (map->map_path[y + 1][x] == '0' || map->map_path[y + 1][x] == 'C'))
				{
					if (map->map_path[y + 1][x] == 'C')
						parse->coin_found++;
					map->map_path[y + 1][x] = 'x';
					modified++;
				}
				if (x + 1 >= 0 && (map->map_path[y][x + 1] == '0' || map->map_path[y][x + 1] == 'C'))
				{
					if (map->map_path[y][x + 1] == 'C')
						parse->coin_found++;
					map->map_path[y][x + 1] = 'x';
					modified++;
				}
				x++;
			}
			y++;
		}
	}
	x = 0;
	y = 0;
	while (map->map_path[y])
	{
		x = 0;
		while (map->map_path[y][x])
		{
			if (map->map_path[y][x] == 'E' && (map->map_path[y - 1][x] == 'x'
			|| map->map_path[y][x - 1] == 'x'||map->map_path[y + 1][x] == 'x'
			||map->map_path[y][x + 1] == 'x'))
			{
				parse->exit_found = 1;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	is_playable_map(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	if (pathfinding(map, parse, item_xy))
	{
		print_map(map, parse);
		ft_putstr("pathfinding check\n");
		return ;
	}
	else
	{
		print_map(map, parse);
		ft_exit("ERROR : the player won't be able to reach coin(s) or exit\n");
	}
}

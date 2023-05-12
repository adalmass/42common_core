/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 15:38:37 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verifications_y(t_map *map, t_parse *parse)
{
	if (map->y - 1 >= 0 && (map->map_path[map->y - 1][map->x] == '0'
		|| map->map_path[map->y - 1][map->x] == 'C'))
	{
		if (map->map_path[map->y - 1][map->x] == 'C')
			parse->coin_found++;
		map->map_path[map->y - 1][map->x] = 'x';
		parse->modified++;
	}
	if (map->y + 1 >= 0 && (map->map_path[map->y + 1][map->x] == '0'
		|| map->map_path[map->y + 1][map->x] == 'C'))
	{
		if (map->map_path[map->y + 1][map->x] == 'C')
			parse->coin_found++;
		map->map_path[map->y + 1][map->x] = 'x';
		parse->modified++;
	}
}

void	verifications_x(t_map *map, t_parse *parse)
{	
	if (map->x - 1 >= 0 && (map->map_path[map->y][map->x - 1] == '0'
		|| map->map_path[map->y][map->x - 1] == 'C'))
	{
		if (map->map_path[map->y][map->x - 1] == 'C')
			parse->coin_found++;
		map->map_path[map->y][map->x - 1] = 'x';
		parse->modified++;
	}
	if (map->x + 1 >= 0 && (map->map_path[map->y][map->x + 1] == '0'
		|| map->map_path[map->y][map->x + 1] == 'C'))
	{
		if (map->map_path[map->y][map->x + 1] == 'C')
			parse->coin_found++;
		map->map_path[map->y][map->x + 1] = 'x';
		parse->modified++;
	}
}

void	pathfinding(t_map *map, t_parse *parse, t_p_xy *p_xy)
{
	map->y = p_xy->spawn_y;
	map->x = p_xy->spawn_x;
	map->map_path[map->y][map->x] = 'x';
	parse->modified = 1;
	while (parse->modified)
	{
		parse->modified = 0;
		map->y = 0;
		while (map->y < map->lines - 1)
		{
			map->x = 0;
			while (map->map_path[map->y][map->x])
			{
				if (map->map_path[map->y][map->x] == 'x')
				{
					verifications_y(map, parse);
					verifications_x(map, parse);
				}
				map->x++;
			}
			map->y++;
		}
	}
}

int	last_verif(t_map *map, t_parse *parse, t_p_xy *p_xy)
{
	if (search_exit(map, parse, p_xy))
		return (1);
	return (0);
}

void	is_playable_map(t_map *map, t_parse *parse, t_p_xy *p_xy)
{
	pathfinding(map, parse, p_xy);
	if (last_verif(map, parse, p_xy)
		&& parse->coin == parse->coin_found
		&& parse->exit_found == 1)
	{
		parse->coin_found = 0;
		return ;
	}
	else
		ft_exit("The player won't be able to reach coin(s) or exit\n");
}

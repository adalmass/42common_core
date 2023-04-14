/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/14 17:51:48 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_visited_path(t_map *map)
{
	char	c;

	c = 'o';
	map->map_path[map->y][map->x] = c;
	if (map->map_path[map->y + 1][map->x] != '1'
		&& map->map_path[map->y + 1][map->x] != c)
		map->map_path[map->y + 1][map->x] = c;
	if (map->map_path[map->y - 1][map->x] != '1'
		&& map->map_path[map->y - 1][map->x] != c)
		map->map_path[map->y - 1][map->x] = c;
	if (map->map_path[map->y][map->x + 1] != '1'
	&& map->map_path[map->y][map->x + 1] != c)
		map->map_path[map->y][map->x + 1] = c;
	if (map->map_path[map->y][map->x - 1] != '1'
		&& map->map_path[map->y][map->x - 1] != c)
		map->map_path[map->y][map->x - 1] = c;
}

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
	else if (map->map_path[map->y][map->x + 1] == 'C')
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
		return (1);
	}
	else if (map->map_path[map->y - 1][map->x] == 'E')
	{
		map->map_path[map->y - 1][map->x] = '1';
		return (1);
	}
	else if (map->map_path[map->y][map->x - 1] == 'E')
	{
		map->map_path[map->y][map->x - 1] = '1';
		return (1);
	}
	else if (map->map_path[map->y][map->x + 1] == 'E')
	{
		map->map_path[map->y][map->x + 1] = '1';
		return (1);
	}
	return (0);
}

void	try_to_move(t_map *map, t_item_xy *item_xy)
{
	if (map->map_path[map->y][map->x + 1] != '1'
		&& map->map_path[map->y][map->x + 1] != 'o')
	{
		map->map_path[map->y][map->x + 1] = 'o';
		map->x++;
		ft_putstr("droite\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y + 1][map->x] != '1'
		&& map->map_path[map->y + 1][map->x] != 'o')
	{
		map->map_path[map->y + 1][map->x] = 'o';
		map->y++;
		ft_putstr("bas\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y][map->x - 1] != '1'
		&& map->map_path[map->y][map->x - 1] != 'o')
	{
		map->map_path[map->y][map->x - 1] = 'o';
		map->x--;
		ft_putstr("gauche\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y - 1][map->x] != '1'
		&& map->map_path[map->y - 1][map->x] != 'o')
	{
		map->map_path[map->y - 1][map->x] = 'o';
		map->y--;
		ft_putstr("haut\n"); // a supp
		return ;
	}
	//map->y = item_xy->spawn_y;
	//map->x = item_xy->spawn_x;

	//ft_putstr("BLOQUÉ du coup je repars du spawn\n");
	map->blocked++;
}

void	pathfinding(t_map *map, t_parse *parse, t_item_xy *item_xy)
{
	if (detect_coin(map))
		parse->coin_get++;
	if (detect_exit(map, parse))
		parse->exit_found++;
	if ((parse->coin_get == parse->coin) && parse->exit_found)
	{
		ft_putstr("pathfinding check\n");
		return ;
	}
	try_to_move(map, item_xy);
	//ft_printf("Je suis en x :%d | y :%d\n", map->x, map->y); // a supp
}

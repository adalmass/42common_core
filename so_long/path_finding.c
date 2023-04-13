/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:02 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 16:08:42 by aldalmas         ###   ########.fr       */
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

void	detect_path(t_map *map)
{
	if (map->map_path[map->y][map->x + 1] != '1'
		&& map->map_path[map->y][map->x + 1] != 'o')
	{
		map->map_path[map->y][map->x + 1] = 'o';
		map->x++;
		ft_putstr("je bouge à droite\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y + 1][map->x] != '1'
		&& map->map_path[map->y + 1][map->x] != 'o')
	{
		map->map_path[map->y + 1][map->x] = 'o';
		map->y++;
		ft_putstr("je bouge en bas\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y][map->x - 1] != '1'
		&& map->map_path[map->y][map->x - 1] != 'o')
	{
		map->map_path[map->y][map->x - 1] = 'o';
		map->x--;
		ft_putstr("je bouge à gauche\n"); // a supp
		return ;
	}
	else if (map->map_path[map->y - 1][map->x] != '1'
		&& map->map_path[map->y - 1][map->x] != 'o')
	{
		map->map_path[map->y - 1][map->x] = 'o';
		map->y--;
		ft_putstr("je bouge en haut\n"); // a supp
		return ;
	}
	ft_putstr("BLOQUÉ\n");
}

int	move_pathfinding(t_map *map, t_parse *parse)
{
	if (detect_coin(map))
		parse->coin_get++;
	if ((parse->coin_get == parse->coin) && parse->exit_found)
	{
		ft_putstr("path finding check\n"); // a supp
		return (1);
	}
	detect_path(map);
	ft_printf("Je suis en x :%d | y :%d\n", map->x, map->y); // a supp
	return (0);
}

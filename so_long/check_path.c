/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:35:27 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/24 18:11:02 by aldalmas         ###   ########.fr       */
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


void	DEBUG_print_map(t_map *map, t_parse *parse)  // a supp
{
	int	y = 0;
	while (map->map_path[y])
	{
		ft_putstr(map->map_path[y]);
		ft_putchar('\n');
		y++;
	}
	ft_printf("Coin(s) recolté(s) : %d/%d\n", parse->coin_found, parse->coin);
	ft_printf("Exit trouvée : %d/1\n", parse->exit_found);
}

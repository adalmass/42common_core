/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:35:27 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 13:56:07 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	DEBUG_print_map(t_map *map, t_parse *parse)  // a supp
{
	int	y = 0;
	while (map->map_path[y])
	{
		ft_putstr(map->map_path[y]);
		ft_putchar('\n');
		y++;
	}
	ft_printf("coins : %d/%d\nexit_found : %d/1\n", parse->coin_found, parse->coin, parse->exit_found);
}

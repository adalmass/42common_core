/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:08:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/07 14:43:26 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_pase(t_parse *parse)
{
	parse->wall = 0;
	parse->path = 0;
	parse->coin = 0;
	parse->exit = 0;
	parse->spawn = 0;
	parse->other_char = 0;
	parse->backslash_n = 0;
}

void	initialize_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->fd = 0;
}

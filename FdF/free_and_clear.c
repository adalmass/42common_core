/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:46:21 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/14 10:13:51 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int	i;

	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
	}
	if (tab)
		free(tab);
}

void	clear_map_int(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			free(map->map_int[y][x]);
			x++;
		}
		free(map->map_int[y]);
		y++;
	}
}

void	clear_map(t_map *map)
{
	return ;
}

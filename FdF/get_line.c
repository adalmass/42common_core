/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:44:43 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/11 18:14:23 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_int(t_map *map)
{
	int	y;
	int	x;
	map->map_int = ft_calloc(sizeof(int), map->map_char_len + 1);
	if (!map->map_int)
		return ;
	y = 0;
	x = 0;
	while (map->map[y])
	{
		//printf("%s\n", map->map[y][x]);
		map->map_int[y] = ft_atoi((char *)map->map[y][x]);
		y++;
	}
	y = 0;
	printf("1\n");
	while (map->map_int[y])
	{
			printf("2\n");
		while (map->map_int[y][x])
		{
			printf("1\n");
			printf("%d", map->map_int[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
		
	}
}

void	get_map_char(t_map *map)
{
	char	*gnl;
	char	*gnl_stock;

	gnl_stock = ft_calloc(sizeof(char), 1);
	if (!gnl_stock)
		return ;
	gnl = get_next_line(map->fd);
	while (gnl != NULL)
	{
		map->map_char_len++;
		gnl_stock = ft_strjoin(gnl_stock, gnl);
		free(gnl);
		gnl = get_next_line(map->fd);
	}
	map->map_char = ft_split(gnl_stock, '\n');
	free(gnl_stock);
	free(gnl);
	gnl_stock = NULL;
	gnl = NULL;
}

void	get_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_char[++i])
		;
	map->map = ft_calloc(sizeof(char **), i + 1);
	if (!map->map)
		return ;
	i = -1;
	while (map->map_char[++i])
		map->map[i] = ft_split(map->map_char[i], ' ');
	map->map[i] = NULL;
}

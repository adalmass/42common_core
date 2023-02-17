/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:39:31 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/17 11:40:20 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_int(t_map *map)
{
	int	y;
	int	x;

	map->x_fd_len = 0;
	map->y_fd_len = 0;
	map->map_int = malloc(sizeof(int *) * map->map_char_len);
	if (!map->map_int)
	{
		free(map->map_int);
		return ;
	}
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			map->map_int[y] = malloc(sizeof(int) * map->map_char_len);
			if (!map->map_int[y])
			{
				free(map->map_int[y]);
				return ;
			}
			map->map_int[y][x] = ft_atoi(map->map[y][x]);
			x++;
		}
		y++;
		map->y_fd_len += 1;
		map->x_fd_len = x;
	}
}

void	get_map_char(t_map *map)
{
	int		readd;
	char	*buf;
	char	*ret;
	char	*tmp;

	ret = ft_strdup("\n");
	buf = ft_calloc(sizeof(char), BUFFER + 1);
	readd = read(map->fd, buf, BUFFER);
	while (readd > 0)
	{
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(tmp);
		free(buf);
		buf = ft_calloc(sizeof(char), BUFFER + 1);
		readd = read(map->fd, buf, BUFFER);
	}
	map->map_char = ft_split(buf, '\n');
	free(ret);
	free(buf);
}

void	get_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_char[i++])
		;
	map->map = ft_calloc(sizeof(char **), i + 1);
	if (!map->map)
		return ;
	i = -1;
	while (map->map_char[++i])
		map->map[i] = ft_split(map->map_char[i], ' ');
	map->map[i] = NULL;
}

void	fill_all_tabs(t_map *map, char *av)
{
	map->fd = open(av, O_RDONLY);
	get_map_char(map);
	get_map(map);
	get_map_int(map);
	close(map->fd);
}
/* Naviguer dans le triple tableau de ses morts la pute
while (map->map[i][++j])
{
	printf("%s", map->map[i][j]);
	printf("\n");
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:24 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/19 15:08:29 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_a_valid_map(char *temp, t_parse *parse)
{
	size_t	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == 'C')
			parse->coin++;
		else if (temp[i] == 'P')
			parse->spawn++;
		else if (temp[i] == 'E')
			parse->exit++;
		else if (temp[i] == '\n' && temp[i + 1] == '\n')
			parse->backslash_n++;
		else if (!search_char("10PEC\n", temp[i]))
		{
			parse->other_char++;
			ft_printf("other char detected : %c\n", temp[i]);
		}
		i++;
	}
	check_if_errors(parse);
	if (temp[i] == '\0')
		return (1);
	exit (1);
}

int	is_wall(t_map *map)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strdup(map->map_path[map->y]);
	while (s[i])
	{
		if (map->y == 0 && s[i] != '1')
			return (0);
		if (map->y == map->lines - 1 && s[i] != '1')
			return (0);
		if (i == 0 && s[i] != '1')
			return (0);
		if (i == map->good_len && s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_walls(t_map *map)
{
	map->y = 0;
	while (map->map_path[map->y])
	{
		if (!is_wall(map))
			ft_exit("ERROR : map not close\n");
		map->y++;
	}
	ft_putstr("map ok\n");
	map->y = 0;
}


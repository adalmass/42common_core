/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:24 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 15:24:38 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_char(char *haystack, char needle)
{
	size_t	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

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
			parse->other_char++;
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
		if (i == 0 && s[i] != '1')
			return (0);
		if ((map->y == 0 && s[i] != '1')
			|| (map->y == map->lines - 1 && s[i] != '1'))
			return (0);
		if (i == map->good_len - 2 && s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	is_valids_walls(t_map *map)
{
	map->y = 0;
	while (map->map_path[map->y])
	{
		if (!is_wall(map))
			ft_exit("ERROR : map not close\n");
		map->y++;
	}
	map->y = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:24 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 11:48:59 by aldalmas         ###   ########.fr       */
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

void	get_map_str(t_map *map)
{
	int	first_turn;
	int	good_len;

	map->map_str = ft_strdup("");
	first_turn = 1;
	while (1)
	{
		map->temp = get_next_line(map->fd);
		if (!map->temp)
			break ;
		if (first_turn)
		{
			map->good_len = s_len(map->temp);
			first_turn = 0;
		}
		if (check_len_size(map, s_len(map->temp)))
			map->map_str = ft_strjoin_gnl(map->map_str, map->temp);
		else
		{
			ft_putstr("ERROR : lines does not have the same size\n");
			exit (1);
		}
		map->lines++;
		free(map->temp);
	}
}

void	get_map(t_map *map, t_parse *parse)
{
	get_map_str(map);
	is_a_valid_map(map->map_str, parse);
	map->map = ft_split(map->map_str, '\n');
	ft_putstr("_{- VALID MAP -}_\n");
}

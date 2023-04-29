/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:45 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/29 13:39:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *error_msg)
{
	ft_putstr("Error\n");
	ft_printf("%s\n", error_msg);
	exit (1);
}

int	check_if_errors(t_parse *parse)
{
	int	error_detected;

	error_detected = 0;
	if (parse->spawn != 1)
	{
		ft_putstr("Error\n");
		ft_putstr("Incorrect SPAWN value (P != 1)\n");
		error_detected++;
	}
	if (parse->exit != 1)
	{
		ft_putstr("Error\n");
		ft_putstr("Incorrect EXIT value (E != 1)\n");
		error_detected++;
	}
	if (parse->coin < 1)
	{
		ft_putstr("Error\n");
		ft_putstr("No COIN found in the map (need 1 coin or more)\n");
		error_detected++;
	}
	error_detected += check_if_errors2(parse);
	if (error_detected)
		exit (1);
	return (0);
}

int	check_if_errors2(t_parse *parse)
{
	int	error_detected;

	error_detected = 0;
	if (parse->other_char > 0)
	{
		ft_putstr("Error\n");
		ft_putstr("Unknow char in map (only '01PEC', case-sensitive)\n");
		error_detected++;
	}
	return (error_detected);
}

int	check_len_size(t_map *map, int actual_len)
{
	if (map->temp[actual_len] == '\0' && map->temp[actual_len - 1] != '\n'
		&& map->good_len == actual_len + 1)
		return (1);
	if (map->good_len == actual_len)
		return (1);
	return (0);
}


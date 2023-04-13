/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:28:53 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 14:33:18 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_parse		parse;
	t_item_xy	item_xy;

	startup_checks(ac, av[1]);
	structs_initializer(&parse, &map, &item_xy);
	map.fd = open(av[1], O_RDONLY);
	if (!check_fd_opening(map.fd))
		exit (1);
	get_map(&map, &parse);

	// on debute la copie de la **map pour pouvoir remplacer les char sans modifier l'original, 
	// puis la recherche de l'entree de la map
	copy_map(&map, &item_xy);
	is_playable_map(&map);
}

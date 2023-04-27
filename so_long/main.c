/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:28:53 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 15:05:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_parse		parse;
	t_item_xy	item_xy;
	t_mlx		mlx;

	startup_checks(ac, av[1]);
	structs_initializer(&parse, &map, &item_xy);
	map.fd = open(av[1], O_RDONLY);
	if (!check_fd_opening(map.fd))
		exit (1);
	get_map(&map, &parse);
	copy_map(&map, &item_xy);
	map.good_len -= 2;
	is_playable_map(&map, &parse, &item_xy);
	//system("leaks so_long");
	//mlx_initializer(&mlx);
	//mlx_loop(mlx.mlx);
	exit (0);
}

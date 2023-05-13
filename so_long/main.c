/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:28:53 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/13 10:27:19 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	startup_checks(ac, av[1]);
	structs_initializer(&game.parse, &game.map, &game.p_xy);
	game.map.fd = open(av[1], O_RDONLY);
	if (!check_fd_opening(game.map.fd))
		exit (1);
	get_map(&game.map, &game.parse);
	copy_map(&game.map, &game.p_xy);
	close(game.map.fd);
	game.map.good_len -= 2;
	is_playable_map(&game.map, &game.parse, &game.p_xy);
	ft_printf("steps counter : 0\n");
	initialize_mlx(&game);
	mlx_loop(game.mlx);
	exit (0);
}

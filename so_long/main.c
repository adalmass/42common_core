/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:28:53 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/07 16:51:06 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_parse	parse;

	startup_checks(ac, av[1]);
	initialize_pase(&parse);
	initialize_map(&map);
	map.fd = open(av[1], O_RDONLY);
	if (!check_fd_opening(map.fd))
		exit (1);
	get_map(&map, &parse);
	system("leaks so_long");
}

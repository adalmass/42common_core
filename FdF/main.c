/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:49:01 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/17 11:40:43 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_img		img;
	t_map		map;
	t_minilbx	mlx;

	if (!check_args_nb(ac) || !check_fd_format(av[1]))
		return (0);
	if (!check_fd_opening(map.fd))
	{
		exit(1);
		return (0);
	}
	struct_initializer(&mlx, &map, &img);
	fill_all_tabs(&map, av[1]);
	mlx_initializer(&mlx, &img);
	fdf(&mlx, &map, &img);
	mlx_loop(mlx.mlx);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:49:01 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/11 17:22:54 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int			fd;
	t_map		map;
	//t_minilbx	minilbx;

	if (!check_args_nb(ac) || !check_fd_format(av[1]))
		return (0);
	if (!check_fd_opening(fd))
		return (0);

	//ft_bzero les variables de ma struct par securite
	ft_bzero(&map, sizeof(t_map));
	//ft_bzero(&minilbx, sizeof(t_minilbx));
	map.fd = open(av[1], O_RDONLY);
	get_map_char(&map);
	get_map(&map);
	get_map_int(&map);

	//minilbx.mlx = mlx_init();
	//minilbx.window = mlx_new_window(minilbx.mlx, 500, 500, "FDF");
	//mlx_loop(minilbx.mlx);
	close(fd);
}

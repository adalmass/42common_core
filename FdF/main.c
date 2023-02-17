/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:49:01 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/16 17:23:23 by aldalmas         ###   ########.fr       */
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
		clear_map_int(&map);
		exit(1);
		return (0);
	}
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&mlx, sizeof(t_minilbx));
	map.fd = open(av[1], O_RDONLY);
	get_map_char(&map);
	get_map(&map);
	get_map_int(&map);
	close(map.fd);
	mlx.mlx = mlx_init();
	check_mlx_init(&mlx);
	mlx.window = mlx_new_window(mlx.mlx, 500, 500, "FDF");
	check_mlx_window(&mlx);
	mlx_hook(mlx.window, 2, 1L << 2, check_event, (void *)0);
	mlx_hook(mlx.window, 17, 1L << 17, shutdown, (void *)0);
	img.img = mlx_new_image(mlx.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	create_img(&mlx, &img);
	while (mlx.x < 400)
	{
		my_mlx_pixel_put(&img, 50 + mlx.x, 50, 0x0000FF);
		my_mlx_pixel_put(&img, 50, 50 + mlx.x, 0xFFFFFF);
		my_mlx_pixel_put(&img, 50 + mlx.x, 50 + 400, 0x00FF00);
		my_mlx_pixel_put(&img, 50 + 400, 50 + mlx.x, 0xFF0000);
		mlx.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	exit(0);
}

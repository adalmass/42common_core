/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:26:00 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/29 17:49:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*save_img(t_game *game, char *img_path)
{
	void	*img;
	int		a;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &a, &a);
	if (!img)
		ft_exit("Can't open xpm\n");
	return (img);
}

void	print_img(t_game *game, void *img, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * SIZE, y * SIZE);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			print_img(game, game->img.floor, y, x);
			if (game->map.map[y][x] == '1')
				print_img(game, game->img.wall, y, x);
			if (game->map.map[y][x] == 'C')
				print_img(game, game->img.coin, y, x);
			if (game->map.map[y][x] == 'P')
				print_img(game, game->img.p_face, y, x);
			x++;
		}
		y++;
	}
}

int	run(t_game	*game)
{
	print_map(game);
	return (0);
}

void	init_img(t_game *game)
{
	game->img.floor = save_img(game, "./images/DEBUG_floor.xpm");
	game->img.wall = save_img(game, "./images/DEBUG_wall.xpm");
	game->img.coin = save_img(game, "./images/coin.xpm");
	game->img.p_face = save_img(game, "./images/p_face.xpm");
	game->img.p_back = save_img(game, "./images/p_back.xpm");
	game->img.p_left = save_img(game, "./images/p_left.xpm");
	game->img.p_right = save_img(game, "./images/p_right.xpm");
}

void	mlx_initializer(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit("Mlx can't be initialized\n");
	game->window = mlx_new_window(game->mlx, (game->map.good_len + 1) * SIZE,
			game->map.lines * SIZE, "so_long");
	if (!game->window)
		ft_exit("Mlx.window can't be opened\n");
	init_img(game);
	mlx_loop_hook(game->mlx, run, game);
	mlx_hook(game->window, 2, 0, key_press, game);
	mlx_hook(game->window, 3, 0, key_release, game);
	mlx_hook(game->window, 17, 0, shutdown, (void *)0);
}

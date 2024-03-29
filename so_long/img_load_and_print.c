/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:39:33 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 10:56:39 by aldalmas         ###   ########.fr       */
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

void	init_img(t_game *game)
{
	game->img.floor = save_img(game, "./images/floor.xpm");
	game->img.wall = save_img(game, "./images/wall.xpm");
	game->img.coin = save_img(game, "./images/coin.xpm");
	game->img.exit = save_img(game, "./images/closed_portal.xpm");
	game->img.exit_open = save_img(game, "./images/opened_portal.xpm");
	game->img.p_face = save_img(game, "./images/p_face.xpm");
	game->img.p_back = save_img(game, "./images/p_back.xpm");
	game->img.p_left = save_img(game, "./images/p_left.xpm");
	game->img.p_right = save_img(game, "./images/p_right.xpm");
	game->img.img_memory = game->img.p_face;
}

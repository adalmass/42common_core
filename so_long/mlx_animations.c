/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:00:45 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/08 13:35:39 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_animation2(t_game *game)
{
	if (game->exit_state == 3)
	{
		game->img.exit = save_img(game, "./images/animation/exit3.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 4)
	{
		game->img.exit = save_img(game, "./images/animation/exit4.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 5)
	{
		game->img.exit = save_img(game, "./images/animation/exit5.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
}

void	exit_animation3(t_game *game)
{
	if (game->exit_state == 6)
	{
		game->img.exit = save_img(game, "./images/animation/exit6.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 7)
	{
		game->img.exit = save_img(game, "./images/animation/exit7.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 8)
	{
		game->img.exit = save_img(game, "./images/animation/exit8.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
}

void	exit_animation4(t_game *game)
{
	if (game->exit_state == 9)
	{
		game->img.exit = save_img(game, "./images/animation/exit9.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 10)
	{
		game->img.exit = save_img(game, "./images/animation/exit10.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
	if (game->exit_state == 11)
	{
		game->img.exit = save_img(game, "./images/animation/exit11.xpm");
		print_img(game, game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
	}
}

void	exit_animation(t_game *game)
{
	if (game->parse.coin_found == game->parse.coin)
	{
		while (game->exit_state < 11)
		{
			game->exit_state++;
			if (game->exit_state == 1)
			{
				game->img.exit = save_img(game, "./images/animation/exit1.xpm");
				print_img(game,
					game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 2)
			{
				game->img.exit = save_img(game, "./images/animation/exit2.xpm");
				print_img(game,
					game->img.exit, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			exit_animation2(game);
			exit_animation3(game);
			exit_animation4(game);
			mlx_do_sync(game->mlx);
			usleep(100050);
		}
	}
}

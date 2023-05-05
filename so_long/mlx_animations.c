/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:00:45 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/05 16:04:59 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_animation(t_game *game)
{
	if (game->parse.coin_found == game->parse.coin)
	{
		while (game->exit_state < 11)
		{
			game->exit_state++;
			if (game->exit_state == 1)
			{
				game->img.portal = save_img(game, "./images/animation/portal1.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 2)
			{
				game->img.portal = save_img(game, "./images/animation/portal2.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 3)
			{
				game->img.portal = save_img(game, "./images/animation/portal3.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 4)
			{
				game->img.portal = save_img(game, "./images/animation/portal4.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 5)
			{
				game->img.portal = save_img(game, "./images/animation/portal5.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 6)
			{
				game->img.portal = save_img(game, "./images/animation/portal6.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 7)
			{
				game->img.portal = save_img(game, "./images/animation/portal7.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 8)
			{
				game->img.portal = save_img(game, "./images/animation/portal8.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);				
			}
			if (game->exit_state == 9)
			{
				game->img.portal = save_img(game, "./images/animation/portal9.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			if (game->exit_state == 10)
			{
				game->img.portal = save_img(game, "./images/animation/portal10.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			
			if (game->exit_state == 11)
			{
				game->img.portal = save_img(game, "./images/animation/portal11.xpm");
				print_img(game, game->img.portal, game->p_xy.exit_y, game->p_xy.exit_x);
			}
			mlx_do_sync(game->mlx);
			usleep(100050);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:51:04 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 13:51:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, int x, int y)
{
	int	i;

	game->map.map[y][x] = game->enemy_mark;
	i = rand() % 4;
	if (i == 0)
		enemy_move_up(game, x, y);
	else if (i == 1)
		enemy_move_down(game, x, y);
	else if (i == 2)
		enemy_move_left(game, x, y);
	else if (i == 3)
		enemy_move_right(game, x, y);
}

void	move_all_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'V' && game->enemy_mark != 'V')
			{
				print_img(game, game->img.enemy, y, x);
				if (!(game->frame % 50))
					move_enemy(game, x, y);
			}
			if (game->map.map[y][x] == 'A' && game->enemy_mark != 'A')
			{
				print_img(game, game->img.enemy, y, x);
				if (!(game->frame % 50))
					move_enemy(game, x, y);
			}
			x++;
		}
		y++;
	}
}

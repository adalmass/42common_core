/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:48:04 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/29 18:11:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->p_xy.spawn_y - 1][game->p_xy.spawn_x] != '1'
		&& game->map.map[game->p_xy.spawn_y - 1][game->p_xy.spawn_x] != 'E')
	{
		print_img(game,
			game->img.floor, game->p_xy.spawn_y, game->p_xy.spawn_x);
		print_img(game,
			game->img.p_back, game->p_xy.spawn_y - 1, game->p_xy.spawn_x);
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = '0';
		game->p_xy.spawn_y -= 1;
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = 'P';
		game->step_counter++;
	}
}

void	move_down(t_game *game)
{
	if (game->map.map[game->p_xy.spawn_y + 1][game->p_xy.spawn_x] != '1'
		&& game->map.map[game->p_xy.spawn_y + 1][game->p_xy.spawn_x] != 'E')
	{
		print_img(game,
			game->img.floor, game->p_xy.spawn_y, game->p_xy.spawn_x);
		print_img(game,
			game->img.p_face, game->p_xy.spawn_y + 1, game->p_xy.spawn_x);
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = '0';
		game->p_xy.spawn_y += 1;
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = 'P';
		game->step_counter++;
	}
}

void	move_left(t_game *game)
{
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x - 1] != '1'
		&& game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x - 1] != 'E')
	{
		print_img(game,
			game->img.floor, game->p_xy.spawn_y, game->p_xy.spawn_x);
		print_img(game,
			game->img.p_left, game->p_xy.spawn_y, game->p_xy.spawn_x - 1);
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = '0';
		game->p_xy.spawn_x -= 1;
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = 'P';
		game->step_counter++;
	}
}

void	move_right(t_game *game)
{
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x + 1] != '1'
		&& game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x + 1] != 'E')
	{
		print_img(game,
			game->img.floor, game->p_xy.spawn_y, game->p_xy.spawn_x);
		print_img(game,
			game->img.p_right, game->p_xy.spawn_y, game->p_xy.spawn_x + 1);
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = '0';
		game->p_xy.spawn_x += 1;
		game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] = 'P';
		game->step_counter++;
	}
}

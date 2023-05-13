/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:48:04 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/13 10:12:21 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_up(t_game *game, int x, int y)
{
	if (game->map.map[y - 1][x] == '0'
		|| game->map.map[y - 1][x] == 'P')
	{
		print_img(game, game->img.floor, y, x);
		print_img(game, game->img.enemy, y - 1, x);
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = game->enemy_mark;
	}
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'V'
		|| game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'A')
	{
		ft_putstr("An enemy trapped you. RIP !\n");
		exit (0);
	}
}

void	enemy_move_down(t_game *game, int x, int y)
{
	if (game->map.map[y + 1][x] == '0'
		|| game->map.map[y + 1][x] == 'P')
	{
		print_img(game, game->img.floor, y, x);
		print_img(game, game->img.enemy, y + 1, x);
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = game->enemy_mark;
	}
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'V'
		|| game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'A')
	{
		ft_putstr("An enemy trapped you. RIP !\n");
		exit (0);
	}
}

void	enemy_move_right(t_game *game, int x, int y)
{
	if (game->map.map[y][x + 1] == '0'
		|| game->map.map[y][x + 1] == 'P')
	{
		print_img(game, game->img.floor, y, x);
		print_img(game, game->img.enemy, y, x + 1);
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = game->enemy_mark;
	}
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'V'
		|| game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'A')
	{
		ft_putstr("An enemy trapped you. RIP !\n");
		exit (0);
	}
}

void	enemy_move_left(t_game *game, int x, int y)
{
	if (game->map.map[y][x - 1] == '0'
		|| game->map.map[y][x - 1] == 'P')
	{
		print_img(game, game->img.floor, y, x);
		print_img(game, game->img.enemy, y, x - 1);
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = game->enemy_mark;
	}
	if (game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'V'
		|| game->map.map[game->p_xy.spawn_y][game->p_xy.spawn_x] == 'A')
	{
		ft_putstr("An enemy trapped you. RIP !\n");
		exit (0);
	}
}

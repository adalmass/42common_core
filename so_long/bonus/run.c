/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:26:00 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 15:38:37 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_text(t_game *game, int y, int x)
{
	char	*s;
	char	*s_steps;
	char	*final_str;

	s = ft_strdup("steps : ");
	s_steps = ft_itoa(game->step_counter);
	final_str = ft_strjoin_gnl(s, s_steps);
	mlx_string_put(game->mlx, game->window, x, y, -1, final_str);
	free(s_steps);
	free(final_str);
}

void	check_enemy(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'V')
		game->enemy_mark = 'A';
	if (game->map.map[y][x] == 'A')
		game->enemy_mark = 'V';
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
				print_img(game, game->img.img_memory, y, x);
			if (game->map.map[y][x] == 'E')
				print_img(game, game->img.exit, y, x);
			check_enemy(game, x, y);
			x++;
		}
		y++;
	}
	move_all_enemy(game);
	print_text(game, 0, 0);
}

int	run(t_game	*game)
{
	game->frame++;
	if (game->frame >= 100)
		game->frame = 0;
	print_map(game);
	if (game->exit_state < 11)
		exit_animation(game);
	return (0);
}

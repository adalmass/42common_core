/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:26:00 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 11:13:21 by aldalmas         ###   ########.fr       */
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
			if (game->map.map[y][x] == 'E' && game->exit_state == 0)
				print_img(game, game->img.exit, y, x);
			else if (game->map.map[y][x] == 'E' && game->exit_state == 1)
				print_img(game, game->img.exit_open, y, x);
			x++;
		}
		y++;
	}
}

int	run(t_game	*game)
{
	print_map(game);
	if (game->parse.coin_found == game->parse.coin)
		game->exit_state = 1;
	return (0);
}

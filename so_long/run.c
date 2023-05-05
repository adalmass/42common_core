/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:26:00 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/05 16:02:14 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	print_text(t_game *game, int y, int x)
{
	char	*s;
	char	*s_steps;
	char	*final_str;

	s = ft_strdup("steps counter :\n");
	s_steps = ft_itoa(game->step_counter);
	final_str = ft_strjoin_gnl(s, s_steps);
	mlx_string_put(game->mlx, game->window, x, y, 0, final_str);
	free(s_steps);
	free(final_str);
}

// void	animate_exit(t_game *game)
// {
// 	if (game->exit_state == 2)
// }

int	if_get_all_coins(t_game *game)
{
	if (game->parse.coin == game->parse.coin_found)
		return (1);
	return (0);
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
			print_text(game, 0, 0);
			print_img(game, game->img.floor, y, x);
			if (game->map.map[y][x] == '1')
				print_img(game, game->img.wall, y, x);
			if (game->map.map[y][x] == 'C')
				print_img(game, game->img.coin, y, x);
			if (game->map.map[y][x] == 'P')
				print_img(game, game->img.img_memory, y, x);
			if (game->map.map[y][x] == 'E')
				print_img(game, game->img.portal, y, x);
			if (game->map.map[y][x] == 'V')
				print_img(game, game->img.enemy, y, x);
			x++;
		}
		y++;
	}
}

int	run(t_game	*game)
{
	print_map(game);
	if (game->exit_state < 11)
		exit_animation(game);
	return (0);
}

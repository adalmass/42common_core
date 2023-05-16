/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:08:34 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/13 11:15:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_parse(t_parse *parse)
{
	parse->wall = 0;
	parse->path = 0;
	parse->coin = 0;
	parse->coin_found = 0;
	parse->exit = 0;
	parse->exit_found = 0;
	parse->spawn = 0;
	parse->other_char = 0;
	parse->backslash_n = 0;
	parse->modified = 0;
}

void	initialize_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->fd = 0;
	map->good_len = 0;
	map->lines = 0;
}

void	initialize_item_xy(t_p_xy *p_xy)
{
	p_xy->exit_x = 0;
	p_xy->exit_y = 0;
	p_xy->spawn_x = 0;
	p_xy->spawn_y = 0;
}

void	structs_initializer(t_parse *parse, t_map *map, t_p_xy *p_xy)
{
	t_game	*game;

	game->exit_state = 1;
	game->step_counter = 0;
	game->frame = 0;
	game->enemy_mark = 'A';
	initialize_parse(parse);
	initialize_map(map);
	initialize_item_xy(p_xy);
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit("Mlx can't be initialized\n");
	game->window = mlx_new_window(game->mlx, (game->map.good_len + 1) * SIZE,
			game->map.lines * SIZE, "so_long");
	if (!game->window)
		ft_exit("Mlx.window can't be opened\n");
	load_images(game);
	mlx_loop_hook(game->mlx, run, game);
	mlx_hook(game->window, 2, 0, key_press, game);
	mlx_hook(game->window, 17, 0, shutdown, (void *)0);
}

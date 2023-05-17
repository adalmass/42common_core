/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:44:59 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/17 16:10:07 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shutdown(void)
{
	ft_printf("[Sortie du programme]\n");
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 53)
		shutdown();
	if (key == 13)
		move_up(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 0)
		move_left(game);
	return (0);
}

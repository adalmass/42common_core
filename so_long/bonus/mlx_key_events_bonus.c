/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:39:44 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/12 11:39:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

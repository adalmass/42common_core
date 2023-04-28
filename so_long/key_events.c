/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:24:31 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/28 13:33:04 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shutdown(void)
{
	ft_printf("[Sortie du programme]\n");
	//system("leaks so_long");
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 53)
		shutdown();
	if (key == 13)
		ft_printf("appuie W\n");
	else if (key == 1)
		ft_printf("appuie A\n");
	else if (key == 2)
		ft_printf("appuie S\n");
	else if (key == 3)
		ft_printf("appuie D\n");
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 13 || key == 1 || key == 2 || key == 3)
		ft_printf("relache\n");
	return (0);
}
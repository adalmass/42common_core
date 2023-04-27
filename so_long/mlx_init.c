/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:26:00 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 14:37:01 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_initializer(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_exit("ERROR : mlx can't be initialized\n");
		mlx->window = mlx_new_window(mlx->mlx, 500, 500, "so_long");
	if (!mlx->window)
		ft_exit("ERROR : mlx.window can't be opened\n");
	mlx_hook(mlx->window, 2, 1L << 2, check_event, (void *)0);
	mlx_hook(mlx->window, 17, 1L << 17, shutdown, (void *)0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:44:54 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/17 11:19:44 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	struct_initializer(t_minilbx *mlx, t_map *map, t_img *img)
{
	ft_bzero(mlx, sizeof(t_minilbx));
	ft_bzero(map, sizeof(t_map));
	ft_bzero(img, sizeof(t_img));
}

void	mlx_initializer(t_minilbx *mlx, t_img *img)
{
	mlx->mlx = mlx_init();
	check_mlx_init(mlx);
	mlx->window = mlx_new_window(mlx->mlx, 500, 500, "FDF");
	check_mlx_window(mlx);
	mlx_hook(mlx->window, 2, 1L << 2, check_event, (void *)0);
	mlx_hook(mlx->window, 17, 1L << 17, shutdown, (void *)0);
}
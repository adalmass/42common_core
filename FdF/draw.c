/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:10:51 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/16 16:24:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	create_img(t_minilbx *mlx, t_img *img)
{
	int	i;

	i = 0;
	while (i < 400)
	{
		// vertical                          x  ,  y
    	mlx_pixel_put(mlx->mlx, mlx->window, 100, 250 + i, 0xFFFFFF);
    	mlx_pixel_put(mlx->mlx, mlx->window, 150, 250 + i, 0x64FE2E);
    	mlx_pixel_put(mlx->mlx, mlx->window, 200, 250 + i, 0xFFFFFF);
		mlx_pixel_put(mlx->mlx, mlx->window, 250, 250 + i, 0x64FE2E);
    	mlx_pixel_put(mlx->mlx, mlx->window, 300, 250 + i, 0xFFFFFF);
    	mlx_pixel_put(mlx->mlx, mlx->window, 350, 250 + i, 0x64FE2E);
		// horizontal
		mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 100, 0xFFFFFF);
    	mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 150, 0x64FE2E);
    	mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 200, 0xFFFFFF);
		mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 250, 0x64FE2E);
    	mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 300, 0xFFFFFF);
    	mlx_pixel_put(mlx->mlx, mlx->window, 250 + i, 350, 0x64FE2E);
		i++;
	}
}

void	fdf(t_minilbx *mlx, t_map *map, t_img *img)
{
	return ;
}

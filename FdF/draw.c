/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:38:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/17 11:38:25 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->lght + x * (img->bpp / 8));
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
	img->img = mlx_new_image(mlx->mlx, 500, 500);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
									&img->lght, &img->endian);
	while (mlx->x < 400)
	{
		put_pixel(img, 50 + mlx->x, 50, 0x0000FF);
		put_pixel(img, 50 + mlx->x, 50 + mlx->x, 0x0000FF);
		put_pixel(img, 50, 50 + mlx->x, 0xFFFFFF);
		put_pixel(img, 50 + mlx->x, 50 + 400, 0x00FF00);
		put_pixel(img, 50 + 400, 50 + mlx->x, 0xFF0000);
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
}

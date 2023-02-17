/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:01:57 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/16 15:05:21 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_args_nb(int ac)
{
	if (ac != 2)
	{
		ft_putstr("[ERROR] Invalid number of argument (!= 2)\n");
		return (0);
	}
	return (1);
}

int	check_fd_format(char *av)
{
	if (!ft_strnstr(av, ".fdf", ft_strlen(av)))
	{
		ft_putstr("[ERROR] Bad fd format (not .fdf)\n");
		return (0);
	}
	return (1);
}

int	check_fd_opening(int fd)
{
	if (fd == -1)
	{
		ft_putstr("[ERROR] File can't be read / does no exist\n");
		return (0);
	}
	return (1);
}

int	check_mlx_init(t_minilbx *mlx)
{
	if (!mlx->mlx)
	{
		ft_printf("[ERROR] mlx_init() failed");
		exit(1);
	}
	return (1);
}

int	check_mlx_window(t_minilbx *mlx)
{
	if (!mlx->window)
	{
		ft_printf("[ERROR] mlx_new_window() failed");
		exit(1);
	}
	return (1);
}

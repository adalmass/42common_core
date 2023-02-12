/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:01:57 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/09 14:25:27 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_args_nb(int ac)
{
	if (ac != 2)
	{
		ft_putstr("error : invalid number of argument (!= 2)\n");
		return (0);
	}
	return (1);
}

int	check_fd_format(char *av)
{
	if (!ft_strnstr(av, ".fdf", ft_strlen(av)))
	{
		ft_putstr("error : bad fd format (not .fdf)\n");
		return (0);
	}
	return (1);
}

int	check_fd_opening(int fd)
{
	if (fd == -1)
	{
		ft_putstr("error : file can't be read / does no exist\n");
		return (0);
	}
	return (1);
}

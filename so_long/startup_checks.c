/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:01:57 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/07 14:43:10 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args_nb(int ac)
{
	if (ac != 2)
	{
		ft_putstr("ERROR : invalid number of argument (!= 2)\n");
		return (0);
	}
	return (1);
}

int	check_fd_format(char *av)
{
	if (!ft_strnstr(av, ".ber", ft_strlen(av)))
	{
		ft_putstr("ERROR : wrong map format (only .ber allowed)\n");
		return (0);
	}
	return (1);
}

int	check_fd_opening(int fd)
{
	if (fd == -1)
	{
		ft_putstr("ERROR : file can't be read / does no exist\n");
		return (0);
	}
	return (1);
}

void	startup_checks(int ac, char *av)
{
	int	check;

	check = 2;
	if (check_args_nb(ac))
		check--;
	if (check_fd_format(av))
		check--;
	if (!check)
		return ;
	exit (1);
}

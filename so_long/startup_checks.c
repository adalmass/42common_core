/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:01:57 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 15:25:58 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args_nb(int ac)
{
	if (ac != 2)
	{
		ft_putstr("ERROR : invalid number of argument (!= 2)\n");
		exit (1);
	}
}

void	check_fd_format(char *av)
{
	if (!ft_strnstr(av, ".ber\0", ft_strlen(av)))
	{
		ft_putstr("ERROR : wrong map format (only .ber allowed)\n");
		exit (1);
	}
}

int	check_fd_opening(int fd)
{
	if (fd == -1)
	{
		ft_putstr("ERROR : file can't be read (does not exist or wrong map format)\n");
		return (0);
	}
	return (1);
}

void	startup_checks(int ac, char *av)
{
	check_args_nb(ac);
	check_fd_format(av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:30:18 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/26 14:14:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	//system("leaks push_swap");
	exit (1);
}

int	check_char_args(char c, char d)
{
	if ((c >= '0' && c <= '9')
		|| (c == '+' && (d >= '0' && d <= '9'))
		|| (c == '-' && (d >= '0' && d <= '9')))
		return (1);
	return (0);
}

void	is_valid_args(char **av)
{
	int	x;
	int	y;

	y = 1;
	while (av[y])
	{
		x = 0;
		while (av[y][x])
		{
			if (!check_char_args(av[y][x], av[y][x + 1]))
				ft_error();
			x++;
		}
		y++;
	}
}

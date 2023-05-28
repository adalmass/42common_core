/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:30:18 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/28 15:21:44 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	exit (1);
}

int	check_char_args(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-'
			&& str[i] != '+' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	is_valid_args(char **av)
{
	int	x;

	x = 1;
	while (av[x] != NULL)
	{
		if (!check_char_args(av[x]))
			ft_error("Invalid character\n");
		x++;
	}
}

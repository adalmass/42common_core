/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_print_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:32:19 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 07:27:06 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	DEBUG_print_tab_a(t_tabs *tabs)
{
	int	y;

	y = 0;
	while (tabs->tab_a[y])
	{
		ft_putchar('[');
		ft_putstr(tabs->tab_a[y]);
		ft_putchar(']');
		ft_putchar('\n');
		y++;
	}
}

void	DEBUG_print_tab_b(t_tabs *tabs)
{
	int	y;

	y = 0;
	while (tabs->tab_b[y])
	{
		ft_putchar('[');
		ft_putstr(tabs->tab_b[y]);
		ft_putchar(']');
		ft_putchar('\n');
		y++;
	}
}
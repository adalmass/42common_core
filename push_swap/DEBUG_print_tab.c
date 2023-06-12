/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_print_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:32:19 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 17:43:43 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	DEBUG_print_tab_a(t_tabs *tabs)
{
	int	y;

	y = 0;
	ft_putstr("TAB A\n");
	while (tabs->tab_a[y])
	{
		ft_printf("i: %d -> [%s]\n", y, tabs->tab_a[y]);
		y++;
	}
}

void	DEBUG_print_tab_b(t_tabs *tabs)
{
	int	y;

	y = 0;
	ft_putstr("TAB B\n");
	while (tabs->tab_b[y])
	{
		ft_printf("i: %d -> [%s]\n", y, tabs->tab_b[y]);
		y++;
	}
}

void	DEBUG_print_copy_a(t_tabs *tab)
{
	int	i;

	i = 0;
	ft_putchar('\n');
	ft_putstr("~TAB copy_a--\n");
	while (tab->copy_a[i])
	{
		ft_printf("%s\n", tab->copy_a[i]);
		i++;
	}
	ft_putstr("--END\n\n");
}

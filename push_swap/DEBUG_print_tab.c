/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_print_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:32:19 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/09 11:30:54 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	DEBUG_print_tab_a(t_tabs *tabs)
{
	int	y;

	y = 0;
	ft_putstr("~TAB_A--\n");
	while (tabs->tab_a[y])
	{
		ft_putstr(tabs->tab_a[y]);
		ft_putchar('\n');
		y++;
	}
	ft_putstr("--END\n\n");
}

void	DEBUG_print_tab_b(t_tabs *tabs)
{
	int	y;

	y = 0;
	ft_putstr("~TAB B--\n");
	while (tabs->tab_b[y])
	{
		ft_putstr(tabs->tab_b[y]);
		ft_putchar('\n');
		y++;
	}
	ft_putstr("--END\n\n");
}

void	DEBUG_print_simple_tab_a(t_tabs *tab)
{
	int	i;

	i = 0;
	ft_putstr("~TAB MAX IDX--\n");
	while (tab->simple_tab_a[i])
	{
		ft_printf("%d\n", tab->simple_tab_a[i], i);
		i++;
	}
	ft_putstr("--END\n\n");
}

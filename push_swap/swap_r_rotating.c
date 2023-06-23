/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_r_rotating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:31:20 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/19 10:53:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_tabs *tab)
{
	int		y;
	char	*temp;

	y = 0;
	while (tab->tab_a[y])
		y++;
	temp = tab->tab_a[y - 1];
	while (y > 1)
	{
		tab->tab_a[y - 1] = tab->tab_a[y - 2];
		y--;
	}
	tab->tab_a[0] = temp;
	tab->count++;
	ft_printf("rra\n");
}

void	rrb(t_tabs *tab)
{
	int		y;
	char	*temp;

	y = 0;
	while (tab->tab_b[y])
		y++;
	temp = tab->tab_b[y - 1];
	while (y > 1)
	{
		tab->tab_b[y - 1] = tab->tab_b[y - 2];
		y--;
	}
	tab->tab_b[0] = temp;
	tab->count++;
	ft_printf("rrb\n");
}

void	rrr(t_tabs *tab)
{
	rra(tab);
	rrb(tab);
	tab->count--;
}

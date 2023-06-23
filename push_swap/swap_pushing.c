/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pushing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:49:58 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/19 10:54:25 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_tabs *tab)
{
	int	y;

	y = 0;
	if (tab->tab_b[0])
	{
		while (tab->tab_a[y])
			y++;
		while (y > 0)
		{
			tab->tab_a[y] = tab->tab_a[y - 1];
			y--;
		}
		tab->tab_a[y] = tab->tab_b[y];
		while (tab->tab_b[y])
		{
			tab->tab_b[y] = tab->tab_b[y + 1];
			y++;
		}
	}
	ft_printf("pa\n");
}

void	pb(t_tabs *tab)
{
	int	y;

	y = 0;
	if (tab->tab_a[0])
	{
		while (tab->tab_b[y])
			y++;
		while (y > 0)
		{
			tab->tab_b[y] = tab->tab_b[y - 1];
			y--;
		}
		tab->tab_b[0] = tab->tab_a[0];
		while (tab->tab_a[y])
		{
			tab->tab_a[y] = tab->tab_a[y + 1];
			y++;
		}
	}
	ft_printf("pb\n");
}

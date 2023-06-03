/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:49:58 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 07:24:52 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_tabs *tab)
{
	int		y;

	y = 0;
	while (tab->tab_b[y] && y < 1)
		y++;
	if (y > 0)
	{
		tab->tab_a[0] = tab->tab_b[0];
		free(tab->tab_b[0]);
	}
	ft_putstr("pa\n");
}

void	push_b(t_tabs *tab)
{
	int		y;

	y = 0;
	while (tab->tab_a[y] && y < 1)
		y++;
	if (y > 0)
	{
		tab->tab_b[0] = tab->tab_a[0];
		free(tab->tab_a[0]);
	}
	ft_putstr("pa\n");
}
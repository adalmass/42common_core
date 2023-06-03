/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotating_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:31:20 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 12:34:04 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_tabs *tab)
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
	ft_putstr("rra\n");
}

void	r_rotate_b(t_tabs *tab)
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
	ft_putstr("rrb\n");
}

void	r_rotate_rrr(t_tabs *tab)
{
	r_rotate_a(tab);
	r_rotate_b(tab);
	ft_putstr("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:28:48 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/05 10:40:33 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_tabs *tab)
{
	int		y;
	int		size;
	char	*temp;

	y = 0;
	size = 0;
	temp = tab->tab_a[0];
	while (tab->tab_a[size])
		size++;
	size--;
	while (y < size)
	{
		if (tab->tab_a[y + 1])
			tab->tab_a[y] = tab->tab_a[y + 1];
		y++;
	}
	tab->tab_a[size] = temp;
	tab->count++;
	ft_putstr("ra\n");
}

void	rotate_b(t_tabs *tab)
{
	int		y;
	int		size;
	char	*temp;

	y = 0;
	size = 0;
	temp = tab->tab_b[0];
	while (tab->tab_b[size])
		size++;
	while (y < size - 1)
	{
		if (tab->tab_b[y + 1])
			tab->tab_b[y] = tab->tab_b[y + 1];
		y++;
	}
	tab->tab_b[size - 1] = temp;
	tab->count++;
	ft_putstr("rb\n");
}

void	rotate_rr(t_tabs *tab)
{
	rotate_a(tab);
	rotate_b(tab);
	tab->count--;
	ft_putstr("rr\n");
}
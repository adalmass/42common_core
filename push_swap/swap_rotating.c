/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:28:48 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 17:53:05 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_tabs *tab)
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

void	rb(t_tabs *tab)
{
	int		y;
	char	*temp;

	y = 0;
	temp = tab->tab_b[0];
	while (tab->tab_b[y])
	{
		tab->tab_b[y] = tab->tab_b[y + 1];
		y++;
	}
	tab->tab_b[y - 1] = temp;
	tab->count++;
	ft_putstr("rb\n");
}

void	rr(t_tabs *tab)
{
	ra(tab);
	rb(tab);
	tab->count--;
	ft_putstr("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotating_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:31:20 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 10:47:58 by aldalmas         ###   ########.fr       */
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
	y = 1;
	while (tab->tab_a[y])
	{
		if (tab->tab_a[y + 1])
			tab->tab_a[y] = tab->tab_a[y];
		y++;
	}
	tab->tab_a[0] = temp;
	ft_putstr("rra\n");
}

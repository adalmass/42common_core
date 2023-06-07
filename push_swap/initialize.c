/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 16:08:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_tabs *tab, int ac, char **av)
{
	tab->max_idx = 0;
	tab->max = 0;
	tab->count = 0;
	tab->len_tab_a = 0;
	tab->tab_a = av + 1;
	tab->tab_b = ft_calloc(ac, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
}

void	make_copy_a(t_tabs *tab)
{
	int	y;

	y = 0;
	tab->copy_a = ft_calloc(tab->len_tab_a - 1, sizeof(int));
	if (!tab->copy_a)
		ft_error("copy_a failed\n");
	while (tab->tab_a[y])
	{
		tab->copy_a[y] = ft_atoi(tab->tab_a[y]);
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/09 11:30:54 by aldalmas         ###   ########.fr       */
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

void	simplify_tab_a(t_tabs *tab)
{
	int	y;

	y = 0;
	tab->simple_tab_a = ft_calloc(tab->len_tab_a - 1, sizeof(int));
	if (!tab->simple_tab_a)
		ft_error("simple_tab_a failed\n");
	while (tab->tab_a[y])
	{
		tab->simple_tab_a[y] = -1;
		y++;
	}
}

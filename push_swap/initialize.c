/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/11 00:17:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_tabs *tab, char **av)
{
	tab->count = 0;
	tab->len_tab_a = 0;
	tab->max = 0;
	tab->max_idx = 0;
	tab->tab_a = av + 1;
	while (tab->tab_a[tab->len_tab_a])
		tab->len_tab_a++;
	tab->len_int_tab_a = tab->len_tab_a;
	tab->copy_a = tab->tab_a;
	tab->tab_b = ft_calloc(tab->len_tab_a, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
	tab->tab_b[tab->len_tab_a] = NULL;
}


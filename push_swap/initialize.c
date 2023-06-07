/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 08:24:36 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_tabs *tab, int ac, char **av)
{
	tab->max = 2147483647;
	tab->count = 0;
	tab->len_tab_a = ac + 1;
	tab->tab_a = av + 1;
	tab->tab_b = ft_calloc(ac, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
	tab->tab_max_idx = ft_calloc(ac, sizeof(int));
	if (!tab->tab_max_idx)
		ft_error("tab_max_idx : calloc failed\n");
}

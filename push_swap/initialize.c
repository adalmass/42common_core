/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 12:44:02 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_tabs *tab, int ac, char **av)
{
	tab->count = 0;
	tab->len_tab_a = 0;
	tab->tab_a = av + 1;
	tab->tab_b = ft_calloc(ac, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
}
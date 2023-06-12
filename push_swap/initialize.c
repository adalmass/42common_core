/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 19:37:25 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_copy_stack(char **stack)
{
	int		i = 0;
	char 	**copy;

	while (stack[i] != NULL)
		i++;
	copy = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (stack[i] != NULL)
	{
		copy[i] = ft_strdup(stack[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	initialize(t_tabs *tab, char **av)
{
	int i = 0;

	tab->count = 0;
	tab->len_tab_a = 0;
	tab->max = 0;
	tab->max_idx = 0;
	tab->tab_a = av + 1;
	while (tab->tab_a[tab->len_tab_a])
		tab->len_tab_a++;

	tab->tab_b = ft_copy_stack(tab->tab_a);
	while (tab->tab_b[i] != NULL)
		tab->tab_b[i++] = ft_strdup(" ");

	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
}

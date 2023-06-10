/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:43:50 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/10 23:26:02 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tabs *tab)
{
	int		y;
	char	*temp;

	y = 0;
	while (tab->tab_a[y] && y < 2)
		y++;
	if (y > 1)
	{
		temp = ft_strdup(tab->tab_a[0]);
		free(tab->tab_a[0]);
		tab->tab_a[0] = ft_strdup(tab->tab_a[1]);
		free(tab->tab_a[1]);
		tab->tab_a[1] = ft_strdup(temp);
		free(temp);
		tab->count++;
		ft_putstr("sa\n");
	}
}

void	sb(t_tabs *tab)
{
	int		y;
	char	*temp;

	y = 0;
	while (tab->tab_b[y] && y < 2)
		y++;
	if (y > 1)
	{
		temp = ft_strdup(tab->tab_b[0]);
		free(tab->tab_b[0]);
		tab->tab_b[0] = ft_strdup(tab->tab_b[1]);
		free(tab->tab_b[1]);
		tab->tab_b[1] = ft_strdup(temp);
		free(temp);
		tab->count++;
		ft_putstr("sb\n");
	}
}

void	ss(t_tabs *tab)
{
	sa(tab);
	sb(tab);
	tab->count--;
	ft_putstr("ss\n");
}

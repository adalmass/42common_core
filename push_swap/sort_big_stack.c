/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:11:47 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/19 12:24:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_b_max(t_tabs *tab, t_push *push)
{
	int	y;

	y = 0;
	push->max = 0;
	push->idx_max = 0;
	while (tab->tab_b[y])
	{
		if (ft_atoi(tab->tab_b[y]) > push->max)
		{
			push->max = ft_atoi(tab->tab_b[y]);
			push->idx_max = y;
		}
		y++;
	}
}

void	push_to_a(t_tabs *tab, t_push *push)
{	
	while (tab->tab_b[0])
	{
		search_b_max(tab, push);
		while (ft_atoi(tab->tab_b[0]) != push->max)
		{
			if (push->idx_max < push->len_tab_b / 2)
				rb(tab);
			else
				rrb(tab);
		}
		if (ft_atoi(tab->tab_b[0]) == push->max)
		{
			pa(tab);
			push->len_tab_b--;
		}
	}
}

void	push_to_b(t_tabs *tab, t_push *push)
{
	int	modif;

	push->len_tab_b = 0;
	while (tab->tab_b[push->len_tab_b])
		push->len_tab_b++;
	while (tab->tab_a[0])
	{
		modif = 0;
		if (ft_atoi(tab->tab_a[0]) <= push->filter)
		{
			pb(tab);
			modif = 1;
			push->filter++;
			push->len_tab_b++;
		}
		else
			rra(tab);
		if (modif == 1)
		{
			if (ft_atoi(tab->tab_b[0]) < push->len_tab_b)
				rb(tab);
		}
	}
}

void	sort_big_stack(t_tabs *tab, t_push *push)
{
	push_to_b(tab, push);
	push_to_a(tab, push);
}

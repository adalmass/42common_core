/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:43:07 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/18 16:58:29 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max(t_tabs *tab)
{
	int	y;
	int	max;

	y = 0;
	max = ft_atoi(tab->tab_a[0]);
	while (tab->tab_a[y])
	{
		if (ft_atoi(tab->tab_a[y]) > max)
			max = ft_atoi(tab->tab_a[y]);
		y++;
	}
	return (max);
}

void	sort_two(t_tabs *tab)
{
	if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		sa(tab);
}

void	sort_three(t_tabs *tab)
{
	int	y;
	int	max;

	y = 0;
	max = search_max(tab);
	while (ft_atoi(tab->tab_a[2]) != max)
		ra(tab);
	if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		sa(tab);
}

void	sort_five2(t_tabs *tab)
{
	pb(tab);
	sort_three(tab);
	pa(tab);
	ra(tab);
	pa(tab);
	ra(tab);
}

void	sort_five(t_tabs *tab)
{
	int	y;
	int	max;

	y = 0;
	max = search_max(tab);
	while (tab->tab_a[y])
	{
		if (max == ft_atoi(tab->tab_a[4]))
			rra(tab);
		if (max == ft_atoi(tab->tab_a[3]))
		{
			rra(tab);
			rra(tab);
		}
		if (ft_atoi(tab->tab_a[0]) != max)
			ra(tab);
		y++;
	}
	pb(tab);
	max = search_max(tab);
	while (max != ft_atoi(tab->tab_a[0]))
	{
		if (max == ft_atoi(tab->tab_a[3]))
			rra(tab);
		else
			ra(tab);
	}
	sort_five2(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:43:07 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/23 11:51:59 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_tabs *tab)
{
	if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		sa(tab);
}

void	sort_three(t_tabs *tab)
{
	if (ft_atoi(tab->tab_a[2]) == 3)
	{
		if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		{
			sa(tab);
			return ;
		}
	}
	if (ft_atoi(tab->tab_a[1]) == 3)
		rra(tab);
	else
		ra(tab);
	if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		sa(tab);
}

void	sort_four(t_tabs *tab)
{
	int	max;

	max = search_max(tab);
	while (ft_atoi(tab->tab_a[0]) != max)
		ra(tab);
	pb(tab);
	if (!is_sorted(tab))
		sort_three(tab);
	pa(tab);
	ra(tab);
}

void	sort_five2(t_tabs *tab)
{
	int	max;

	max = search_max(tab);
	while (max != ft_atoi(tab->tab_a[0]))
	{
		if (max == ft_atoi(tab->tab_a[3]))
			rra(tab);
		else
			ra(tab);
	}
	pb(tab);
	sort_three(tab);
	pa(tab);
	ra(tab);
	pa(tab);
	ra(tab);
}

void	sort_five(t_tabs *tab)
{
	int	max;

	max = search_max(tab);
	while (tab->tab_a[0])
	{
		if (max == ft_atoi(tab->tab_a[4]))
			rra(tab);
		else if (max == ft_atoi(tab->tab_a[3]))
		{
			rra(tab);
			rra(tab);
		}
		if (ft_atoi(tab->tab_a[0]) != max)
			ra(tab);
		else
			break ;
	}
	pb(tab);
	sort_five2(tab);
}

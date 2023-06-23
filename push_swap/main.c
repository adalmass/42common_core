/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/23 12:27:25 by aldalmas         ###   ########.fr       */
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

int	is_sorted(t_tabs *tab)
{
	int	y;

	y = 0;
	while (tab->tab_a[y + 1])
	{
		if (ft_atoi(tab->tab_a[y]) > ft_atoi(tab->tab_a[y + 1]))
			return (0);
		y++;
	}
	return (1);
}

void	sort_stack(t_tabs *tab)
{
	t_push	push;

	if (tab->len_tab_a == 2)
		sort_two(tab);
	else if (tab->len_tab_a == 3)
		sort_three(tab);
	else if (tab->len_tab_a == 4)
		sort_four(tab);
	else if (tab->len_tab_a == 5)
		sort_five(tab);
	if (tab->len_tab_a > 5)
	{
		if (tab->len_tab_a < 101)
			push.filter = 12;
		else if (tab->len_tab_a < 501)
			push.filter = 30;
		sort_big_stack(tab, &push);
	}	
}

int	main(int ac, char **av)
{
	t_tabs	tab;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	initialize(&tab, av);
	is_valid_args(av);
	parse_tab_a(&tab);
	handle_tab_a(&tab);
	create_tab_b(&tab);
	if (!is_sorted(&tab))
		sort_stack(&tab);
	exit (0);
}

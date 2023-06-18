/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/18 17:14:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_tabs *tab)
{
	int	y;

	y = 0;
	while (tab->tab_a[y + 1])
	{
		if (tab->tab_a[y] > tab->tab_a[y + 1])
			return (0);
		y++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_tabs	tab;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	is_valid_args(av);
	initialize(&tab, av);
	parse_tab_a(&tab);
	handle_tab_a(&tab);
	// verifier si deja trie, si oui exit sinon merde
	if (ac < 3)
		sort_two(&tab);
	else if (ac < 4)
		sort_three(&tab);
	else if (ac < 6)
		sort_five(&tab);
	else if (ac > 6 && ac <101)
		// changer le filtre a 15
	else if (ac > 100 && ac < 501)
		// filtre 25
	
	//DEBUG_print_tab_a(&tab);
	//DEBUG_print_tab_a(&tab);
	//ft_printf("-[Tri effectué en %d coup(s)]-\n", tab.count);
	exit (0);
}

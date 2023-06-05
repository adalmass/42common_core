/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/05 16:41:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tabs	tab;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	is_valid_args(av);
	initialize(&tab, ac, av);
	parse_tab_a(&tab);
	if (ac == 3)
		sort_two(&tab);
	//else if (ac == 4)
	//	sort_three(&tab);
	//elif (ac == 6)
	//	sort_five(&tab);
	sort_big_stack(&tab);
	DEBUG_print_tab_a(&tab);
	ft_printf("-[Tri effectué en %d coup(s)]-\n", tab.count);
	exit (0);
}

	//DEBUG_print_tab_b(&tab);
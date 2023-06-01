/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/01 18:24:59 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tabs	tabs;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	is_valid_args(av);
	tabs.tab_a = av + 1;
	parse_tab_a(&tabs);
	DEBUG_print_tab_a(&tabs); // à suppr
	
	// --- TESTS
	// ft_printf("[before sorting]\n");
	// DEBUG_print_tab_a(&tabs); // à suppr
	// swap_a(&tabs);
	// ft_printf("[after sorting]\n");
	// DEBUG_print_tab_a(&tabs);
	//system("leaks push_swap");
	exit (0);
}

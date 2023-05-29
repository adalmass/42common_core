/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/29 16:16:53 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	t_tabs	tabs;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	is_valid_args(av);
	parse.args = av;
	create_tab_a(&parse, &tabs);
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

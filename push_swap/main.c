/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 10:03:47 by aldalmas         ###   ########.fr       */
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
	tabs.tab_b = ft_calloc(ac, sizeof(char *));
	if (!tabs.tab_b)
		ft_error("tab_b : calloc failed\n");
	parse_tab_a(&tabs);
	DEBUG_print_tab_a(&tabs);
	r_rotate_a(&tabs);
	DEBUG_print_tab_a(&tabs);
	exit (0);
}

	// tabs.tab_b[0] = "3";
	// tabs.tab_b[1] = "45";
	// tabs.tab_b[2] = "13";
	// tabs.tab_b[2] = "98";
	// tabs.tab_b[3] = "7";
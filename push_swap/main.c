/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/16 19:19:33 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tabs	tab;

	if (ac == 1)
		ft_error("Args must be > 1\n");
	is_valid_args(av);
	initialize(&tab, av);
	parse_tab_a(&tab);
	handle_tab_a(&tab);
	pb(&tab);
	pb(&tab);
	pb(&tab);
	pb(&tab);
	pb(&tab);
	ft_printf("fin du push_b\n");
	DEBUG_print_tab_a(&tab);
	DEBUG_print_tab_b(&tab);
	//push_to_b(&tab, 4);
	exit (0);
}

	//ft_printf("-[Tri effectué en %d coup(s)]-\n", tab.count);
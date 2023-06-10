/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/11 00:36:17 by aldalmas         ###   ########.fr       */
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
	// peut-etre strjoin avant de split dans parse_tab_a pour gerer 
	// si en arg il y a "41           32". Mon prog sort 4132 collés
	// P-e un bug
	parse_tab_a(&tab);
	DEBUG_print_tab_a(&tab);
	sort_copy_a(&tab);
	DEBUG_print_copy_a(&tab);
	simplify_tab_a(&tab);
	ft_printf("Apres simplification\n");
	DEBUG_print_tab_a(&tab);
	//ft_printf("-[Tri effectué en %d coup(s)]-\n", tab.count);
	exit (0);
}

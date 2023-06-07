/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 16:40:58 by aldalmas         ###   ########.fr       */
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
	// peut-etre strjoin avant de split dans parse_tab_a pour gerer 
	// si en arg il y a "41           32". Mon prog sort 4132 collés
	// P-e un bug
	parse_tab_a(&tab);
	while (tab.tab_a[tab.len_tab_a])
		tab.len_tab_a++;
	tab.tab_max_idx = ft_calloc(tab.len_tab_a, sizeof(char *));
	if (!tab.tab_max_idx)
		ft_error("tab_max_idx : calloc failed\n");
	make_copy_a(&tab);
	DEBUG_print_tab_a(&tab);
	simplify_nb(&tab);
	DEBUG_print_copy_a(&tab);
	//ft_printf("-[Tri effectué en %d coup(s)]-\n", tab.count);
	exit (0);
}

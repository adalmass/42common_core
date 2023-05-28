/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/28 13:54:19 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	t_tabs	tabs;

	if (ac == 1)
		return (0);
	initialize_struct(&parse);
	is_valid_args(av);
	parse.args = av;
	create_tab_a(&parse, &tabs);
	DEBUG_print_tab_a(&tabs); // à suppr
	exit (0);
}

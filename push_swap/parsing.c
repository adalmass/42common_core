/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/26 21:03:54 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// jai besoin de creer le tableau pour ensuite verifier 
// si je nai pas des zeros devant mes chiffres et de doubles
void	create_tab_a(t_parse *parse, t_tabs *tabs)
{
	char	*temp_tab_a;
	char	*without_zeros;

	parse->y = 1;
	temp_tab_a = ft_strdup("");
	while (parse->args[parse->y])
	{
		if (parse->args[parse->y][0] == '+')
			parse->args[parse->y] = ft_strdup(parse->args[parse->y] + 1);
		//if (av[y][0] == '-')
			// l ecrire puis i++ jusqu a trouver un digit non 0 valide
		if (parse->args[parse->y][0] == '0')
			without_zeros = manage_zeros(parse);
		else
			without_zeros = ft_strdup(parse->args[parse->y]);
		temp_tab_a = ft_strjoin_gnl(temp_tab_a, without_zeros);
		temp_tab_a = ft_strjoin_gnl(temp_tab_a, "\n");
		free(without_zeros);
		parse->y++;
	}

	tabs->tab_a = ft_split(temp_tab_a, '\n');
	free(temp_tab_a);
	check_if_double(tabs);
}

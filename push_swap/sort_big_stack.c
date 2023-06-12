/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:11:47 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 17:47:30 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len(char **tab_b)
{
	int	y;

	y = 0;
	while (tab_b[y])
		y++;
	return (y);
}

void	push_to_b(t_tabs *tab, int filter)
{
	int	a;
	int	b;
	int	modif;

	b = 0;
	modif = 1;
	while (modif)
	{
		a = 0;
		modif = 0;
		while (tab->tab_a[a])
		{
			DEBUG_print_tab_b(tab);
			ft_printf("\nNOUVEAU TOUR\nValeur a: %s\n", tab->tab_a[a]);
			ft_printf("Valeur b: %s\n", tab->tab_b[b]);
			if (ft_atoi(tab->tab_a[a]) <= filter)
			{
				pb(tab);
				filter++;
				modif = 1;
			}
			if (modif && (ft_atoi(tab->tab_b[b]) <= (tab->len_tab_a / 2)))
				rb(tab);
			a++;
			b++;
		}
	}
}

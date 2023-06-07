/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:29:46 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 08:38:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_str(t_tabs *tab, int idx)
{
	char	*temp;

	temp = tab->tab_a[idx];
	tab->tab_a[idx] = tab->tab_a[idx + 1];
	tab->tab_a[idx + 1] = temp;
}

int	compare_str(t_tabs *tab, int idx)
{
	int	str1;
	int	str2;

	str1 = ft_atoi(tab->tab_a[idx]);
	str2 = ft_atoi(tab->tab_a[idx + 1]);
	if (str1 > str2)
	{
		swap_str(tab, idx);
		return (1);
	}
	return (0);
}


void	search_max(t_tabs *tab)
{
	int	y;
	int	max;
	int	idx_max;

	max = ft_atoi(tab->tab_a[0]);
	y = 1;
	idx_max = 0;
	while (tab->tab_a[y])
	{
		if (ft_atoi(tab->tab_a[y]) > max)
		{
			max = ft_atoi(tab->tab_a[y]);
			idx_max = y;
		}
		y++;
	}
	ft_printf("max: %d\nidx_max: %d\n", max, idx_max);
}

void	simplify_nb(t_tabs *tab)
{
	// il faut lancer une boucle qui va enregister l'idx du max dans un
	// tableau afin de simplifier les nb. 
	// ex : 145 est a la 3e position dans tab_a (taille de 5), 
	// il aura donc la valeur de 5 a l'idx 2 du tab_idx.
}

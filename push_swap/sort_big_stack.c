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
	int	i;
	int	temp;
	int	modified;

	i = 0;
	temp = 0;
	modified = 0;
	tab->max = 0;
	while (tab->copy_a[i])
	{
		if (tab->copy_a[i] > tab->max)
		{
			tab->max = i;
			modified = 1;
			ft_printf("max found at idx %d\n", tab->max);
		}
		i++;
	}
	if (modified || i == 0)
	{
		tab->copy_a[tab->max] = tab->len_tab_a;
		tab->len_tab_a--;
	}
}

void	simplify_nb(t_tabs *tab)
{
	int	i;
	int	search_again;

	i = 0;
	search_again = 1;
	while (search_again)
	{
		search_again = 0;
		if ((!tab->copy_a[i]) && (i != tab->len_tab_a)) // il faut modif cette condition qui n'est plus bonne avec copy_a (tab d'int)
		{
			search_again = 1;
			break ;
		}
		i++;
	}
	if (search_again)
		search_max(tab);
}
	// il faut lancer une boucle qui va enregister l'idx du max dans un
	// tableau afin de simplifier les nb. 
	// ex : 145 est a la 3e position dans tab_a (taille de 5), 
	// il aura donc la valeur de 5 a l'idx 2 du tab_idx.


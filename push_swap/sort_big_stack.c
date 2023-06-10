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

void	sort_copy_a(t_tabs *tab)
{
	int		y;
	int		modified;
	char	*temp;

	modified = 1;
	temp = NULL;
	while (modified)
	{
		modified = 0;
		y = 0;
		while (tab->copy_a[y + 1])
		{
			if (ft_atoi(tab->copy_a[y]) > ft_atoi(tab->copy_a[y + 1]))
			{
				temp = tab->copy_a[y];
				tab->copy_a[y] = tab->copy_a[y + 1];
				tab->copy_a[y + 1] = temp;
				modified = 1;
			}
			y++;
		}
	}
}

void	simplify_tab_a(t_tabs *tab)
{
	int	y;
	int	z;

	y = 0;
	while (tab->tab_a[y])
	{
		z = 0;
		while (tab->copy_a[z])
		{
			if (ft_atoi(tab->tab_a[y]) == ft_atoi(tab->copy_a[z]))
				tab->tab_a[y] = ft_itoa(z);
			z++;
		}
		y++;
	}
}

/*
// void	update_int_tab_a(t_tabs *tab)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (tab->copy_a[i])
// 	{
// 		ft_printf("tout va bien ici\n");
// 		if (tab->copy_a[i] == tab->max)
// 			i++;
// 		tab->copy_a[j] = tab->copy_a[i];
// 		i++;
// 		j++;
// 	}
// 	new_max(tab);
// 	DEBUG_print_copy_a(tab);
// }

// void	new_max(t_tabs *tab)
// {
// 	int	y;

// 	y = 0;
// 	while (tab->copy_a[y] != tab->max)
// 	{
// 		y = 0;
// 		while (tab->copy_a[y])
// 		{
// 			if (tab->copy_a[y] == tab->max)
// 				break ;
// 			y++;
// 		}
// 		tab->max--;
// 	}
// }

// void	search_max(t_tabs *tab)
// {
// 	int	y;
// 	int	modified;

// 	y = 0;
// 	modified = 0;
// 	while (tab->copy_a[y])
// 	{
// 		if (tab->copy_a[y] > tab->max)
// 		{
// 			tab->max = tab->copy_a[y];
// 			ft_printf("new max: %d\n", tab->max);
// 			tab->max_idx = y;
// 			modified = 1;
// 		}
// 		y++;
// 	}
// 	if (modified == 1)
// 	{
// 		ft_printf("je numerote le max\n");
// 		tab->simplified_nb[tab->max_idx] = tab->len_tab_a;
// 		tab->len_tab_a--;
// 		update_int_tab_a(tab);
// 	}
// 	else if (modified == 0 && tab->tab_a[y] == '\0')
// 	{
// 		ft_printf("j'arrete la recherche\n");
// 		tab->max_idx = -1;
// 	}
// }

// void	simplify_nb(t_tabs *tab)
// {
// 	int	i;
// 	int	search_again;

// 	i = 0;
// 	search_again = 1;
// 	while (search_again)
// 	{
// 		search_again = 0;
// 		if (tab->simplified_nb[i] == -1)
// 		{
// 			search_again = 1;
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (search_again)
// 		search_max(tab);
// }

// void	jsp(t_tabs *tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab->max_idx != -1)
// 	{
// 		simplify_nb(tab);
// 		i++;
// 	}
// }
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:29:46 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/05 17:25:35 by aldalmas         ###   ########.fr       */
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

void	sort_big_stack(t_tabs *tab)
{
	int	y;
	int	modified;

	y = 0;
	modified = 1;
	while (modified)
	{
		modified = 0;
		y = 0;
		while (tab->tab_a[y])
		{
			if (ft_atoi(tab->tab_a[y]) < tab->max)
			{
				modified = 1;
				tab->max = ft_atoi(tab->tab_a[y]);
				tab->tab_idx[tab->len_tab_a] = tab->len_tab_a;
				tab->len_tab_a--;
			}
			y++;
		}
	}
	// quand on a fini de bouclé plus haut, on verifie s'il y a des elements dans tab_idx. 
	// s'il n'est pas completement rempli ca veut dire qu'il reste des max a chercher donc on rappelera sort_big_Stack()
	DEBUG_print_tab_idx(tab);
}

// void	sort_big_stack(t_tabs *tab)
// {
// 	int		y;
// 	int		modified;
// 	modified = 1;
// 	while (modified)
// 	{
// 		y = 0;
// 		modified = 0;
// 		while (tab->tab_a[y])
// 		{
// 			if (tab->tab_a[y + 1] != '\0')
// 			{
// 				if (compare_str(tab, y))
// 				{
// 					tab->count++;
// 					modified = 1;
// 				}
// 			}
// 			y++;
// 		}
// 	}
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:29:46 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/03 13:27:34 by aldalmas         ###   ########.fr       */
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

	if (s_len(tab->tab_a[idx]) > s_len(tab->tab_a[idx + 1]))
	{
		swap_str(tab, idx);
		return (1);
	}
	str1 = ft_atoi(tab->tab_a[idx]);
	str2 = ft_atoi(tab->tab_a[idx + 1]);
	if (str1 > str2)
	{
		swap_str(tab, idx);
		return (1);
	}
	return (0);
}

void	sort_three(t_tabs *tab) // BUG A FIX ICI, PEUT ETRE MODIFIED QUI FAIT CHIER
{
	int		y;
	int		modified;

	y = 0;
	modified = 1;
	while (modified)
	{
		modified = 0;
		while (tab->tab_a[y])
		{
			if (tab->tab_a[y + 1])
			{
				ft_printf("size y : %d\nsize y + 1 : %d]\n", s_len(tab->tab_a[y]), s_len(tab->tab_a[y + 1]));
				if (compare_str(tab, y))
				{
					tab->count++;
					modified = 1;
				}
			}
			y++;
		}
	}
}
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

int	search_max(t_tabs *tab)
{
	int	y;
	int	temp;
	int	modified;

	y = 0;
	temp = 0;
	modified = 0;
	while (tab->tab_a[y])
	{
		if (ft_atoi(tab->tab_a[y]) > tab->max)
		{
			tab->max = ft_atoi(tab->tab_a[y]);
			tab->max_idx = y;
			modified = 1;
		}
		y++;
	}
	if (modified || y == 0)
	{
		tab->simple_tab_a[tab->max_idx] = tab->len_tab_a;
		tab->len_tab_a--;
		return (1);
	}
	if (!modified)
	{
		ft_printf("!modified\n");
		return (0);
	}
	return (0);
}

void	simplify_nb(t_tabs *tab)
{
	int	i;
	int	finish;
	int	search_again;

	i = 0;
	finish = 1;
	search_again = 1;
	while (search_again)
	{
		search_again = 0;
		if ((tab->simple_tab_a[i] == -1) && (i != tab->len_tab_a))
		{
			search_again = 1;
			break ;
		}
		i++;
	}
	if (search_again)
	{
		while (finish)
		{
			finish = search_max(tab);
			ft_printf("valeur finish: %d\n", finish);
		}
	}
}
